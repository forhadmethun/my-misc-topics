#!/usr/bin/env python3

import argparse, codecs, hashlib, os, sys # do not use any other imports/libraries
from pyasn1.codec.der import decoder, encoder

# took x.y hours (please specify here how much time your solution required)


# parse arguments
parser = argparse.ArgumentParser(description='issue TLS server certificate based on CSR', add_help=False)
parser.add_argument("private_key_file", help="Private key file (in PEM or DER form)")
parser.add_argument("CA_cert_file", help="CA certificate (in PEM or DER form)")
parser.add_argument("csr_file", help="CSR file (in PEM or DER form)")
parser.add_argument("output_cert_file", help="File to store certificate (in PEM form)")
args = parser.parse_args()

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

def asn1_bitstring(bitstr):
    # bitstr - string containing bitstring (e.g., "10101")
    # returns DER encoding of BITSTRING
    count = 0
    string_length = len(bitstr)
    byte_len = 0
    while count < string_length:
        count += 8
        byte_len+=1
    pad_length = count - string_length
    for i in range(0, pad_length):
        bitstr = bitstr + '0'

    str_list = [bitstr[i: i + 8] for i in range(0, len(bitstr), 8)]
    int_list = []
    for s in str_list:
        int_list.append(bin_string_to_int(s))

    integer_to_encode_as_byte = bytes(int_list)
    integer_to_encode_as_byte = (nb(pad_length) if pad_length > 0 else bytes([0x00])) + integer_to_encode_as_byte
    return bytes([0x03]) + asn1_len(integer_to_encode_as_byte) + integer_to_encode_as_byte

def asn1_integer(i):
    # i - arbitrary integer (of type 'int' or 'long')
    # returns DER encoding of INTEGER
    # print("--: ", i)
    integer_to_encode_as_byte = nb(i)
    if((integer_to_encode_as_byte[0] & (1 << 7)) > 0):
            integer_to_encode_as_byte = bytes([0x00]) + integer_to_encode_as_byte
    # length = len(integer_to_encode_as_byte)
    return bytes([0x02]) + asn1_len(integer_to_encode_as_byte) + integer_to_encode_as_byte

def asn1_boolean(bool):
    # BOOLEAN encoder has been implemented for you
    if bool:
        bool = b'\xff'
    else:
        bool = b'\x00'
    return bytes([0x01]) + asn1_len(bool) + bool


def asn1_utctime(time):
    # time - bytes containing timestamp in UTCTime format (e.g., b"121229010100Z")
    # returns DER encoding of UTCTime
    return bytes([0x17]) + asn1_len((time)) + time

def asn1_tag_explicit(der, tag):
    # der - DER encoded bytestring
    # tag - tag value to specify in the type octet
    # returns DER encoding of original DER that is encapsulated in tag type

    return bytes([_type_class_context_defined|_type_form_constructed|tag]) + asn1_len((der)) + der


# end of code copied for asn1

#==== ASN1 encoder end ====

def pem_to_der(content):
    # converts PEM content (if it is PEM) to DER
    if content.endswith(b'-----\n'):
        content = content.decode('utf-8')
        content = content.replace('-----BEGIN PUBLIC KEY-----\n', '')
        content = content.replace('-----BEGIN RSA PRIVATE KEY-----\n', '')
        content = content.replace('-----END PUBLIC KEY-----\n', '')
        content = content.replace('-----END RSA PRIVATE KEY-----\n', '')
        content = content.replace('-----BEGIN CERTIFICATE REQUEST-----\n', '')
        content = content.replace('-----BEGIN CERTIFICATE-----\n', '')
        content = content.replace('-----END CERTIFICATE-----\n', '')
        content = content.replace('-----END CERTIFICATE REQUEST-----\n', '')
        content = codecs.decode(content.encode(), 'base64')
    return content


def get_privkey(filename):
    # reads private key file and returns (n, d)
    privkey = [0, 0, 0]
    keyfile = open(filename, 'rb')
    # decode the DER to get public key DER structure, which is encoded as BITSTRING
    privkey = decoder.decode(pem_to_der(keyfile.read()))
    return int(privkey[0][1]), int(privkey[0][3])


def pkcsv15pad_sign(plaintext, n):
    # pad plaintext for signing according to PKCS#1 v1.5

    # calculate byte size of modulus n

    # plaintext must be at least 3 bytes smaller than modulus

    # add padding bytes
    length = (n.bit_length() + 7) // 8
    plaintext_byte = plaintext
    padding_string_length = length - (len(plaintext) + 3)
    if (padding_string_length < 0):
        sys.exit(1)
    padding_string = b''
    while padding_string_length > 0:
        padding_string += bytes([0xff])
        padding_string_length -= 1
    padded_plaintext = bytes([0x00, 0x01]) + padding_string + bytes([0]) + plaintext
    return padded_plaintext
# openssl x509 -outform der -in certificate.pem -out certificate.der
# openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365
# priv.pem UT_rootCA.pem auth.ut.ee.csr out.auth.ut.ee.csr
# openssl x509 -req -sha256 -days 365 -in server.csr -signkey server.key -out server.crt
# openssl x509 -req -in mydomain.com.csr -CA rootCA.crt -CAkey rootCA.key -CAcreateserial -out mydomain.com.crt -days 500 -sha256
# openssl x509 -req -in auth.ut.ee.csr -CA UT_rootCA.pem -CAkey priv.pem -CAcreateserial -out mydomain.com.crt -days 500 -sha256

def digestinfo_der(filename):
    # returns ASN.1 DER encoded DigestInfo structure containing SHA256 digest of file
    file = filename # open(filename, "rb")
    m = hashlib.sha256()
    m.update(file)#.read())
    der = asn1_sequence(
        asn1_sequence(
            # asn1_objectidentifier([2, 16, 840, 1, 101, 3, 4, 2, 1])  # 2.16.840.1.101.3.4.2.1
            asn1_objectidentifier([1, 2, 840, 113549, 1, 1, 11])  # 2.16.840.1.101.3.4.2.1
            + asn1_null()
        )
        + asn1_octetstring(m.digest())
    )
    return der


def sign(m, keyfile):
    # sign DigestInfo of message m
    n, d = get_privkey(keyfile)
    # ciphertextfile = open(filetosign, 'rb')
    # signaturefile = open(signaturefile, 'wb')
    # signature_der = digestinfo_der(ciphertextfile)
    signature_der = digestinfo_der(m)
    padded_sig_der = pkcsv15pad_sign(signature_der, n)
    m = bn(padded_sig_der)
    s = pow(m, d, n)
    # signaturefile.write(nb(s))
    # signaturefile.close()
    # signature = nb(s)
    return int_to_bin_string(s);
    # return signature


def get_subject_cn(csr_der):
    # return CommonName value from CSR's Distinguished Name
    # decoder.decode(csr_der)[0][0][1][1][0][1]
    # looping over Distinguished Name entries until CN found
    i = 0
    while( str(decoder.decode(csr_der)[0][0][1][i][0][0]) != '2.5.4.3'):
        i += 1
    x = str(decoder.decode(csr_der)[0][0][1][i][0][1])
    return x

def get_subjectPublicKeyInfo(csr_der):

    # returns DER encoded subjectPublicKeyInfo from CSR
    # return decoder.decode(csr_der)[0][0][2]
    pub = decoder.decode(csr_der)[0][0][2]
    obj_identifier_list = list(map(int, str(pub[0][0]).split('.')));
    der = asn1_sequence(
        asn1_sequence(
            asn1_objectidentifier(obj_identifier_list)  # 2.16.840.1.101.3.4.2.1
            + asn1_null()
        )
        + encoder.encode(pub[1])
        # + asn1_octetstring(b'axa'.digest())
    )
    return der

def get_subjectName(cert_der):
    # return subject name DER from CA certificate
    return encoder.encode(decoder.decode(cert_der)[0][0][5])

def issue_certificate(private_key_file, issuer, subject, pubkey):
    # receives CA private key filename, DER encoded CA Distinguished Name, constructed DER encoded subject's Distinguished Name, DER encoded subjectPublicKeyInfo
    # returns X.509v3 certificate in PEM format
    # start: tbsCertificate
    tbsCertificate = asn1_sequence(
        asn1_tag_explicit(asn1_integer(2), 0) +
        asn1_integer(33554617) +
        # pubkey +
        encoder.encode(decoder.decode(pubkey)[0][0]) +
        issuer +
        asn1_sequence(
            asn1_utctime(b"200329010100Z") +
            asn1_utctime(b"200629010100Z")
        ) +
        subject
        +
        pubkey
        +
        asn1_tag_explicit(
            asn1_sequence(
                # basic constraints
                asn1_sequence(
                    asn1_objectidentifier([2, 5, 29, 19]) +
                    asn1_boolean(True) +
                    asn1_octetstring(
                        asn1_sequence(
                            asn1_boolean(True) +
                            asn1_integer(3)
                        )
                    )
                ) +
                # key usage
                asn1_sequence(
                    asn1_objectidentifier([2, 5, 29, 15]) +
                    asn1_boolean(True) +
                    asn1_octetstring(
                        # asn1_sequence(
                        #     asn1_boolean(True) +
                        #     asn1_integer(0)
                        # )
                        asn1_bitstring('01100000')
                    )
                ) +
                #extended key usage
                asn1_sequence(
                    asn1_objectidentifier([1, 3, 6, 1, 5, 5, 7, 3, 1]) +
                    asn1_boolean(True) +
                    asn1_octetstring(
                        asn1_boolean(True)
                        # asn1_sequence(
                        #     asn1_boolean(True) +
                        #     asn1_integer(3)
                        # )
                    )
                )
            )
            , 3)
    )
    # end: tbsCertificate
    pem = asn1_sequence(
            tbsCertificate +
            # start : signatureAlgorithm
            encoder.encode(decoder.decode(pubkey)[0][0]) +
            # end : signatureAlgorithm
            # start : signatureValue
            asn1_bitstring(sign(tbsCertificate,private_key_file))
            # asn1_bitstring(sign(subject,private_key_file))
            # end : signatureValue

    )
    p = b'-----BEGIN CERTIFICATE-----\n'
    p += codecs.encode(pem, 'base64');
    # p += b'\n'
    p += b'-----END CERTIFICATE-----\n';
    pem = p
    # "".join(map(chr, pem))
    return pem

# obtain subject's CN from CSR
csr_der = pem_to_der(open(args.csr_file, 'rb').read())
subject_cn_text = get_subject_cn(csr_der)

print("[+] Issuing certificate for \"%s\"" % (subject_cn_text))

# obtain subjectPublicKeyInfo from CSR
pubkey = get_subjectPublicKeyInfo(csr_der)

# construct subject name DN
subject =  encoder.encode(decoder.decode(csr_der)[0][0][1])#...

# get subject name DN from CA certificate
CAcert = pem_to_der(open(args.CA_cert_file, 'rb').read())
CAsubject = get_subjectName(CAcert)

# issue certificate
cert_pem = issue_certificate(args.private_key_file, CAsubject, subject, pubkey)
open(args.output_cert_file, 'wb').write(cert_pem)
