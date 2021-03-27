#!/usr/bin/python3

# do not use any other imports/libraries
import codecs
import hashlib
import datetime
import sys
import zipfile

# apt-get install python3-bs4 python3-pyasn1-modules python3-ecdsa python3-m2crypto python3-lxml
from ecdsa import VerifyingKey
from bs4 import BeautifulSoup
from pyasn1.codec.der import decoder, encoder
from pyasn1_modules import rfc2560

# took x.y hours (please specify here how much time your solution required)

# verifies signature using ECDSA with SHA384
def verify_ecdsa(cert, signature_value, signed_msg):
    import M2Crypto
    X509 = M2Crypto.X509.load_cert_der_string(cert)
    pk = X509.get_pubkey()
    pubkey = pk.as_der() # public key info structure

    # ecdsa-sha384:
    vk = VerifyingKey.from_der(pubkey)
    return vk.verify(signature_value, signed_msg, hashfunc=hashlib.sha384)

# extracts from TSA response the timestamp and timestamped DigestInfo
def parseTsaResponse(timestamp_resp):
    timestamp = decoder.decode(timestamp_resp)
    tsinfo = decoder.decode(timestamp[0][1][2][1])[0]
    ts_digestinfo = encoder.encode(tsinfo[2])
    ts = datetime.datetime.strptime(str(tsinfo[4]), '%Y%m%d%H%M%SZ')
    # let's assume that timestamp has been issued by a trusted TSA
    return ts, ts_digestinfo

# extracts from OCSP response certID_serial, certStatus and thisUpdate
def parseOcspResponse(ocsp_resp):
    ocspResponse, _ = decoder.decode(ocsp_resp, asn1Spec=rfc2560.OCSPResponse())
    responseStatus = ocspResponse.getComponentByName('responseStatus')
    assert responseStatus == rfc2560.OCSPResponseStatus('successful'), responseStatus.prettyPrint()
    responseBytes = ocspResponse.getComponentByName('responseBytes')
    responseType = responseBytes.getComponentByName('responseType')
    assert responseType == rfc2560.id_pkix_ocsp_basic, responseType.prettyPrint()
    response = responseBytes.getComponentByName('response')
    basicOCSPResponse, _ = decoder.decode(response, asn1Spec=rfc2560.BasicOCSPResponse())
    tbsResponseData = basicOCSPResponse.getComponentByName('tbsResponseData')
    response0 = tbsResponseData.getComponentByName('responses').getComponentByPosition(0)
    # let's assume that OCSP response has been signed by a trusted OCSP responder
    certID = response0.getComponentByName('certID')
    # let's assume that issuer name and key hashes in certID are correct
    certID_serial = certID[3]
    certStatus = response0.getComponentByName('certStatus').getName()
    thisUpdate = datetime.datetime.strptime(str(response0.getComponentByName('thisUpdate')), '%Y%m%d%H%M%SZ')

    return certID_serial, certStatus, thisUpdate


# returns XML canonicalization of element with specified tagname
def canonicalize(full_xml, tagname):
    if type(full_xml)!=bytes:
        print("[-] canonicalize(): input not xml:", type(full_xml))
        exit(1)
    import io
    import lxml.etree as ET
    input = io.BytesIO(full_xml)
    et = ET.parse(input)
    output = io.BytesIO()
    ET.ElementTree(et.find('.//{*}'+tagname)).write_c14n(output)
    return output.getvalue()

# returns CommonName value from certificate's Subject Distinguished Name field
def get_subject_cn(cert_der):
    # looping over Distinguished Name entries until CN found
    i = 0
    while (str(decoder.decode(cert_der)[0][0][5][i][0][0]) != '2.5.4.3'):
        i += 1
    x = str(decoder.decode(cert_der)[0][0][5][i][0][1])
    return x
    # return ''

filename = sys.argv[1]


# get and decode xml
archive = zipfile.ZipFile(filename, 'r')
xml = archive.read('META-INF/signatures0.xml')

xmldoc = BeautifulSoup(xml, features="xml")
# let's trust this certificate
signers_cert_der = codecs.decode(xmldoc.XAdESSignatures.KeyInfo.X509Data.X509Certificate.encode_contents(), 'base64')
print("[+] Signatory:", get_subject_cn(signers_cert_der))
signed_file  = xmldoc.XAdESSignatures.Signature.SignedInfo.Reference['URI']
print("[+] Signed file:",signed_file)

sign_time_stamp = (codecs.decode(xmldoc.XAdESSignatures.Signature.Object.QualifyingProperties.UnsignedProperties.SignatureTimeStamp.EncapsulatedTimeStamp.encode_contents(), 'base64'))
# sign_time_stamp = (codecs.decode(xmldoc.SignatureTimeStamp.EncapsulatedTimeStamp.encode_contents(), 'base64'))


# print("[+] Timestamped:", xmldoc.XAdESSignatures.Object.QualifyingProperties.SignedProperties.SignedSignatureProperties.SigningTime.get_text())
print("[+] Timestamped:", parseTsaResponse(sign_time_stamp)[0])
#xmldoc.XAdESSignatures.Object.QualifyingProperties.SignedProperties.SignedSignatureProperties.SigningTime



# perform all kinds of checks

# check 1: signature of signed info check
canonicalize_signed_info = canonicalize(xml, "SignedInfo")
signature_value_signed_info_hashed = hashlib.sha256(canonicalize_signed_info).hexdigest()
signature_value_signed_info = codecs.decode(xmldoc.XAdESSignatures.Signature.SignatureValue.encode_contents(), 'base64')
m = hashlib.sha256()


signed_info_str = hashlib.sha256(canonicalize_signed_info).digest()
signature_value =             codecs.decode(xmldoc.XAdESSignatures.Signature.SignatureValue.encode_contents(), 'base64')
# these two value should be same but signed_info_str gives 32 byte, but signature_value gives 96 byte :/



# check 2: signature of file check
signed_file_open = archive.read(signed_file)
file_calculated_digest = hashlib.sha256(signed_file_open).digest()
signed_value_from_xml1 = codecs.decode(xmldoc.XAdESSignatures.Signature.SignedInfo.find('Reference').DigestValue
                                            .encode_contents(), 'base64')

# check 3: signature of signed properties check
canonicalize_signed_properties = hashlib.sha256(canonicalize(xml, "SignedProperties")).digest()
signed_value_from_xml2 = codecs.decode(xmldoc.XAdESSignatures.Signature.SignedInfo.findAll('Reference')[1].DigestValue
                                            .encode_contents(), 'base64')

# check 4: ...


# finally verify signatory's signature
if file_calculated_digest != signed_value_from_xml1:
    print("[-] Hash value of file doesn't match with file Digest Value!")
# elif verify_ecdsa(signers_cert_der, signature_value, signed_info_str):
#    print("[-] a wrong certificate hash included under the signature!")

# elif signed_info_str != signature_value:
#     print("[-] a wrong certificate hash included under the signature!")

elif canonicalize_signed_properties != signed_value_from_xml2:
    print("[-] Signed Properties doesn't match with Signed Properties Digest Value!")
else:
    print("[+] Signature verification successful!")