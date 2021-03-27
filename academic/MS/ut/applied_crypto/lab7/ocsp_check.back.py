#!/usr/bin/env python3

import codecs, datetime, hashlib, re, sys, socket # do not use any other imports/libraries
from urllib.parse import urlparse
from pyasn1.codec.der import decoder, encoder
from pyasn1.type import namedtype, univ

# sudo apt install python3-pyasn1-modules
from pyasn1_modules import rfc2560, rfc5280

# took x.y hours (please specify here how much time your solution required)

def nb(i, length=False):
    # converts integer to bytes
    b = b''
    if length==False:
        length = (i.bit_length()+7)//8
    for _ in range(length):
        b = bytes([i & 0xff]) + b
        i >>= 8
    return b

def bn(b):
    # converts bytes to integer
    i = 0
    for char in b:
        i <<= 8
        i |= char
    return i

#==== ASN1 encoder start ====
# put your DER encoder functions here
# code copied for asn1
_buffer_size = 512
_type_form_constructed = 1 << 5
_type_class_context_defined = 2 << 6

def asn1_sequence(der):
    # der - DER bytes to encapsulate into sequence
    # returns DER encoding of SEQUENCE
    return bytes([0x10 | _type_form_constructed]) + asn1_len((der)) + der


def asn1_len(value_bytes):
    # helper function - should be used in other functions to calculate length octet(s)
    # value_bytes - bytes containing TLV value byte(s)
    # returns length (L) byte(s) for TLV
    if len(value_bytes) < 128:
        b = bytes([len(value_bytes)])
    else:
        integer_to_encode_as_byte = nb(len(value_bytes))
        b = bytes([(1 << 7 | len(integer_to_encode_as_byte))]) + integer_to_encode_as_byte
    return b


def nb(value_bytes):
    integer_to_encode_as_byte_list = []
    if (value_bytes == 0):
        integer_to_encode_as_byte_list.insert(0, 0)
    else:
        while value_bytes != 0:
            integer_to_encode_as_byte_list.insert(0, value_bytes & 255)
            value_bytes = value_bytes >> 8
    b = bytes(integer_to_encode_as_byte_list)
    return b


def bin_string_to_int(str):
    i = 0
    for bit in str:
        i <<= 1
        if bit == '1':
            i |= 1
    return i


def int_to_bin_string(int):
    if (int == 0):
        return '0'
    val = ''
    while (int != 0):
        val = (chr((int % 2) + 48)) + val
        int = int >> 1
    return val


def asn1_objectidentifier(oid):
    # oid - list of integers representing OID (e.g., [1,2,840,123123])
    # returns DER encoding of OBJECTIDENTIFIER
    int_list = []
    for i in range(2, len(oid)):
        bitstr = int_to_bin_string(oid[i])

        count = 0
        string_length = len(bitstr)
        byte_len = 0
        while count < string_length:
            count += 7
            byte_len += 1
        pad_length = count - string_length
        for i in range(0, pad_length):
            bitstr = '0' + bitstr

        str_list = [bitstr[i: i + 7] for i in range(0, len(bitstr), 7)]
        for j in range(0, len(str_list)):
            if (j == len(str_list) - 1):
                str_list[j] = '0' + str_list[j]
            else:
                str_list[j] = '1' + str_list[j]

        for s in str_list:
            int_list.append(bin_string_to_int(s))
    integer_to_encode_as_byte = bytes(int_list)
    integer_to_encode_as_byte = bytes([oid[0] * 40 + oid[1]]) + integer_to_encode_as_byte

    return bytes([0x6]) + asn1_len((integer_to_encode_as_byte)) + integer_to_encode_as_byte


def asn1_null():
    # returns DER encoding of NULL
    return bytes([0x05]) + asn1_len(b'')


def asn1_octetstring(octets):
    # octets - arbitrary byte string (e.g., b"abc\x01")
    # returns DER encoding of OCTETSTRING
    return bytes([0x04]) + asn1_len((octets)) + octets

def asn1_tag_explicit(der, tag):
    # der - DER encoded bytestring
    # tag - tag value to specify in the type octet
    # returns DER encoding of original DER that is encapsulated in tag type

    return bytes([_type_class_context_defined|_type_form_constructed|tag]) + asn1_len((der)) + der
def asn1_integer(i):
    # i - arbitrary integer (of type 'int' or 'long')
    # returns DER encoding of INTEGER
    # print("--: ", i)
    integer_to_encode_as_byte = nb(i)
    if((integer_to_encode_as_byte[0] & (1 << 7)) > 0):
            integer_to_encode_as_byte = bytes([0x00]) + integer_to_encode_as_byte
    # length = len(integer_to_encode_as_byte)
    return bytes([0x02]) + asn1_len(integer_to_encode_as_byte) + integer_to_encode_as_byte

# end of code copied for asn1

#==== ASN1 encoder end ====



def pem_to_der(content):
    # converts PEM encoded X.509 certificate (if it is PEM) to DER
    if content.endswith(b'-----\n'):
        content = content.decode('utf-8')
        content = content.replace('-----BEGIN CERTIFICATE-----\n', '')
        content = content.replace('-----END CERTIFICATE-----\n', '')
        content = codecs.decode(content.encode(), 'base64')
    return content
    return content

def get_name(cert):
    # get subject DN from certificate
    return name

def get_key(cert):
     # get subjectPublicKey from certificate
    return subjectPublicKey

def get_serial(cert):
    # get serial from certificate
    return serial

def produce_request(cert, issuer_cert):
    # make OCSP request in ASN.1 DER form

    # construct CertID (use SHA1)
    serial = decoder.decode(cert)[0][0][1]
    print("[+] Querying OCSP for serial:", serial)

    # construct entire OCSP request
    # OCSPRequest
    request = asn1_sequence(
        #TBSRequest
        asn1_sequence(
            #version
            # asn1_tag_explicit(asn1_integer(0), 0) +
            #requestList
            asn1_sequence(
                #certID
                asn1_sequence(
                    #hash algorithm
                    asn1_objectidentifier([1, 3, 14, 3, 2, 26])
                    +
                    #issuer name
                    # asn1_octetstring(hashlib.sha1(encoder.encode(decoder.decode(issuer_cert)[0][0][3])).digest()) #.hexdigest()
                    +asn1_octetstring(hashlib.sha1(encoder.encode(decoder.decode(cert)[0][0][3])).digest()) #.hexdigest()
                    # encoder.encode(decoder.decode(issuer_cert)[0][0][3])
                    #issuer key hash
                    +
                    # hashlib.sha1().update(
                    #     # decoder.decode(issuer_cert)[0][0][6][1]
                    #     # int_to_bin_string(bn(decoder.decode(issuer_cert)[0][0][6][1]))
                    #       nb(bn(decoder.decode(issuer_cert)[0][0][6][1]))
                    # ).hexdigest()
                    asn1_octetstring(hashlib.sha1(asn1_octetstring(nb(bn(decoder.decode(cert)[0][0][6][1])))).digest())
                    +asn1_octetstring(hashlib.sha1(asn1_octetstring(nb(bn(decoder.decode(issuer_cert)[0][0][6][1])))).digest())
                    +asn1_octetstring(hashlib.sha1(asn1_octetstring(nb(bin_string_to_int(str(decoder.decode(cert)[0][0][6][1]))))).digest())
                    +asn1_octetstring(hashlib.sha1(asn1_octetstring(nb(bin_string_to_int(str(decoder.decode(issuer_cert)[0][0][6][1]))))).digest())
                    # asn1_octetstring(hashlib.sha1(asn1_octetstring(encoder.encode(decoder.decode(cert)[0][0][6][1]))).digest())
                    #serial number
                    +
                    # asn1_octetstring(nb(decoder.decode(issuer_cert)[0][0][1]))
                    asn1_integer((decoder.decode(cert)[0][0][1]))

                )
            )
        )
    )
    ocsp_file = open('ocsp.der','wb')
    ocsp_file.write(request)
    ocsp_file.close()
    return request

def send_req(ocsp_req, ocsp_url):
    # send OCSP request to OCSP responder

    # parse ocsp responder url
    host = urlparse(ocsp_url).netloc
    print("[+] Connecting to %s..." % (host))
    # connect to host

    # send HTTP POST request

    # read HTTP response header

    # get HTTP response length

    # read HTTP response body
    # url = urlparse(ocsp_url)
    netloc = urlparse(ocsp_url).netloc
    path = urlparse(ocsp_url).path
    # connect to host
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((netloc, 80))
    # sent HTTP GET request

    # headers = """\
    # POST {path} HTTP/1.1\r
    # Content-Type: {content_type}\r
    # Content-Length: {content_length}\r
    # Host: {host}\r
    # \r\n"""
    # body_bytes = ocsp_req
    # header_bytes = headers.format(
    #     path=path,
    #     content_type="application/ocsp-request",
    #     content_length=len(body_bytes),
    #     host=netloc
    # ).encode('iso-8859-1')
    # payload = header_bytes + body_bytes
    # s.send(payload)
    request_data = b'POST ' + path.encode() + b' HTTP/1.1\r\nHost: ' + netloc.encode()  + b'\r\n'  + b'Content-Type: application/ocsp-request\r\n' + b'Content-Length: '+ nb(len(ocsp_req)) + b'\r\n\r\n' + ocsp_req + b'\r\n\r\n'
    # s.send(b'POST ' + path.encode() + b' HTTP/1.1\r\nHost: ' + netloc.encode()  + b'\r\n'  + b'Content-Type: application/ocsp-request\r\n' + b'Content-Length: '+ nb(len(ocsp_req)) + b'\r\n\r\n' + ocsp_req + b'\r\n\r\n')
    s.send(request_data)
    # read HTTP response header
    header = b''
    while True:

        if ('\r\n\r\n' in header.decode()):
            break
        b = s.recv(1)
        header += b
    # get HTTP response length
    response_length = int(re.search('content-length:\s*(\d+)\s', header.decode(), re.S + re.I).group(1))
    # read HTTP response body
    ocsp_resp = s.recv(response_length)



    return ocsp_resp

def get_ocsp_url(cert):
    # get OCSP url from certificate's AIA extension

    # pyasn1 syntax description to decode AIA extension
    class AccessDescription(univ.Sequence):
      componentType = namedtype.NamedTypes(
        namedtype.NamedType('accessMethod', univ.ObjectIdentifier()),
        namedtype.NamedType('accessLocation', rfc5280.GeneralName()))

    class AuthorityInfoAccessSyntax(univ.SequenceOf):
      componentType = AccessDescription()

    # looping over certificate extensions
    for seq in decoder.decode(cert)[0][0][7]:
        if str(seq[0])=='1.3.6.1.5.5.7.1.1': # look for AIA extension
            ext_value = bytes(seq[1])
            for aia in decoder.decode(ext_value, asn1Spec=AuthorityInfoAccessSyntax())[0]:
                if str(aia[0])=='1.3.6.1.5.5.7.48.1': # ocsp url
                    return str(aia[1].getComponentByName('uniformResourceIdentifier'))

    print("[-] OCSP url not found in certificate!")
    exit(1)

def get_issuer_cert_url(cert):
    # get CA certificate url from certificate's AIA extension (hint: see get_ocsp_url())
    class AccessDescription(univ.Sequence):
        componentType = namedtype.NamedTypes(
            namedtype.NamedType('accessMethod', univ.ObjectIdentifier()),
            namedtype.NamedType('accessLocation', rfc5280.GeneralName()))

    class AuthorityInfoAccessSyntax(univ.SequenceOf):
        componentType = AccessDescription()

    # looping over certificate extensions
    for seq in decoder.decode(cert)[0][0][7]:
        if str(seq[0]) == '1.3.6.1.5.5.7.1.1':  # look for AIA extension
            ext_value = bytes(seq[1])
            for aia in decoder.decode(ext_value, asn1Spec=AuthorityInfoAccessSyntax())[0]:
                if str(aia[0]) == '1.3.6.1.5.5.7.48.2':  # cert url
                    return str(aia[1].getComponentByName('uniformResourceIdentifier'))

    print("[-] CA certificate url not found in certificate!")
    exit(1)
    # pass
# done
def download_issuer_cert(issuer_cert_url):
    print("[+] Downloading issuer certificate from:", issuer_cert_url)

    # parse ocsp responder url
    url = urlparse(ocsp_url)
    netloc = urlparse(issuer_cert_url).netloc
    path = urlparse(issuer_cert_url).path
    # connect to host
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((netloc, 80))
    # sent HTTP GET request
    s.send(b'GET ' + path.encode() + b' HTTP/1.1\r\nHost: ' + netloc.encode() + b'\r\n\r\n')

    # read HTTP response header
    header = b''
    while True:

        if ('\r\n\r\n' in header.decode()):
            break
        b = s.recv(1)
        header += b
    # get HTTP response length
    response_length = int(re.search('content-length:\s*(\d+)\s', header.decode(), re.S+re.I).group(1))
    # read HTTP response body
    issuer_cert = s.recv(response_length)
    # while response_length > 0:
    #     response_length -= 1
    #     issuer_cert += s.recv(1)

    return issuer_cert

# parses OCSP response
def parse_ocsp_resp(ocsp_resp):
    ocspResponse, _ = decoder.decode(ocsp_resp, asn1Spec=rfc2560.OCSPResponse())
    responseStatus = ocspResponse.getComponentByName('responseStatus')
    assert responseStatus == rfc2560.OCSPResponseStatus('successful'), responseStatus.prettyPrint()
    responseBytes = ocspResponse.getComponentByName('responseBytes')
    responseType = responseBytes.getComponentByName('responseType')
    assert responseType == rfc2560.id_pkix_ocsp_basic, responseType.prettyPrint()

    response = responseBytes.getComponentByName('response')

    basicOCSPResponse, _ = decoder.decode(
        response, asn1Spec=rfc2560.BasicOCSPResponse()
    )

    tbsResponseData = basicOCSPResponse.getComponentByName('tbsResponseData')

    response0 = tbsResponseData.getComponentByName('responses').getComponentByPosition(0)

    producedAt = datetime.datetime.strptime(str(tbsResponseData.getComponentByName('producedAt')), '%Y%m%d%H%M%SZ')
    certID = response0.getComponentByName('certID')
    certStatus = response0.getComponentByName('certStatus').getName()
    thisUpdate = datetime.datetime.strptime(str(response0.getComponentByName('thisUpdate')), '%Y%m%d%H%M%SZ')

    # let's assume that certID in response matches the certID sent in the request

    # let's assume that response signed by trusted responder

    print("[+] OCSP producedAt:", producedAt)
    print("[+] OCSP thisUpdate:", thisUpdate)
    print("[+] OCSP status:", certStatus)

cert = pem_to_der(open(sys.argv[1], 'rb').read())

ocsp_url = get_ocsp_url(cert)
print("[+] URL of OCSP responder:", ocsp_url)

issuer_cert_url = get_issuer_cert_url(cert)
issuer_cert = download_issuer_cert(issuer_cert_url)

ocsp_req = produce_request(cert, issuer_cert)
ocsp_resp = send_req(ocsp_req, ocsp_url)
parse_ocsp_resp(ocsp_resp)
