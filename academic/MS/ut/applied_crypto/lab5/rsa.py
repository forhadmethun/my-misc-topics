#!/usr/bin/env python3

import codecs, hashlib, os, sys  # do not use any other imports/libraries
from pyasn1.codec.der import decoder

# took 5.5 hours (please specify here how much time your solution required)

# code copied for asn1
_buffer_size = 512
_type_form_constructed = 1 << 5


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


# end of code copied for asn1
def nb(i, length=False):
    # converts integer to bytes
    b = b''
    if length == False:
        length = (i.bit_length() + 7) // 8
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


def pem_to_der(content):
    # converts PEM content to DER
    if content.endswith(b'-----\n'):
        content = content.decode('utf-8')
        content = content.replace('-----BEGIN PUBLIC KEY-----\n', '')
        content = content.replace('-----BEGIN RSA PRIVATE KEY-----\n', '')
        content = content.replace('-----END PUBLIC KEY-----\n', '')
        content = content.replace('-----END RSA PRIVATE KEY-----\n', '')
        content = codecs.decode(content.encode(), 'base64')
    return content

def get_pubkey(filename):
    # reads public key file and returns (n, e)
    pubkey = [0, 0]
    keyfile = open(filename, 'rb')
    # decode the DER to get public key DER structure, which is encoded as BITSTRING
    der = pem_to_der(keyfile.read())
    bitstring = str(decoder.decode(der)[0][1])
    # convert BITSTRING to bytestring
    bytestring = bytes(int(bitstring[i: i + 8], 2) for i in range(0, len(bitstring), 8))
    pubkey[0] = decoder.decode(bytestring)[0][0]
    pubkey[1] = decoder.decode(bytestring)[0][1]
    return int(pubkey[0]), int(pubkey[1])



def get_privkey(filename):
    # reads private key file and returns (n, d)
    privkey = [0, 0, 0]
    keyfile = open(filename, 'rb')
    # decode the DER to get public key DER structure, which is encoded as BITSTRING
    privkey = decoder.decode(pem_to_der(keyfile.read()))
    return int(privkey[0][1]), int(privkey[0][3])


def pkcsv15pad_encrypt(plaintext, n):
    # pad plaintext for encryption according to PKCS#1 v1.5

    # calculate number of bytes required to represent the modulus n

    # plaintext must be at least 11 bytes smaller than the modulus

    # generate padding bytes
    padded_plaintext = b''
    length = (n.bit_length() + 7) // 8
    plaintext_byte = plaintext
    padding_string_length = length - (len(plaintext) + 3)
    padding_string = b''
    if (padding_string_length < 8):
        sys.exit(1)
    while padding_string_length > 0:
        random_char = os.urandom(1)
        if bn(random_char) == 0:
            continue
        padding_string += random_char
        padding_string_length -= 1
    padded_plaintext = bytes([0x00, 0x02]) + padding_string + bytes([0x00]) + plaintext
    return padded_plaintext


def pkcsv15pad_sign(plaintext, n):
    # pad plaintext for signing according to PKCS#1 v1.5

    # calculate byte length of modulus n

    # plaintext must be at least 3 bytes smaller than modulus

    # generate padding bytes
    padded_plaintext = b''
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


def pkcsv15pad_remove(plaintext):
    # removes PKCS#1 v1.5 padding
    starting = False
    output = b''
    for i, b in enumerate(plaintext):
        if starting:
            output = output + bytes([b])
            continue
        if i == 0 or i == 1:
            continue
        if b == 0:
            starting = True
    plaintext = output
    return plaintext


def encrypt(keyfile, plaintextfile, ciphertextfile):
    # keyfile = open(keyfile,'rb')
    n, e = get_pubkey(keyfile)
    plaintextfile = open(plaintextfile, 'rb')
    ciphertextfile = open(ciphertextfile, 'wb')
    m = bn(pkcsv15pad_encrypt(plaintextfile.read(), n))
    c = pow(m, e, n)
    ciphertextfile.write(nb(c))
    ciphertextfile.close()


def decrypt(keyfile, ciphertextfile, plaintextfile):
    n, d = get_privkey(keyfile)
    ciphertextfile = open(ciphertextfile, 'rb')
    plaintextfile = open(plaintextfile, 'wb')
    c = bn(ciphertextfile.read())
    m = pow(c, d, n)
    # m = bn(pkcsv15pad_encrypt(plaintextfile.read(), n))
    ptext = pkcsv15pad_remove(nb(m))
    plaintextfile.write(ptext)
    plaintextfile.close()


def digestinfo_der(filename):
    # returns ASN.1 DER encoded DigestInfo structure containing SHA256 digest of file
    file = filename # open(filename, "rb")
    m = hashlib.sha256()
    m.update(file.read())
    der = asn1_sequence(
        asn1_sequence(
            asn1_objectidentifier([2, 16, 840, 1, 101, 3, 4, 2, 1])  # 2.16.840.1.101.3.4.2.1
            + asn1_null()
        )
        + asn1_octetstring(m.digest())
    )
    return der

def sign(keyfile, filetosign, signaturefile):
    # Warning: make sure that signaturefile produced has the same
    # length as the modulus (hint: use parametrized nb()).
    n, d = get_privkey(keyfile)
    ciphertextfile = open(filetosign, 'rb')
    signaturefile = open(signaturefile, 'wb')
    signature_der = digestinfo_der(ciphertextfile)
    padded_sig_der = pkcsv15pad_sign(signature_der, n)
    m = bn(padded_sig_der)
    s = pow(m, d, n)
    signaturefile.write(nb(s))
    signaturefile.close()

def verify(keyfile, signaturefile, filetoverify):
    # prints "Verified OK" or "Verification failure"
    n, e = get_pubkey(keyfile)
    signaturefile = open(signaturefile, 'rb')
    filetoverify = open(filetoverify,'rb')
    filetoverify_der = digestinfo_der(filetoverify)
    s = bn(signaturefile.read())
    m = pow(s, e, n)
    filetoverify_der_from_signaturefile = pkcsv15pad_remove(nb(m))
    if filetoverify_der != filetoverify_der_from_signaturefile:
        print("Verification failure")
    else:
        print("Verified OK")

def usage():
    print
    "Usage:"
    print
    "encrypt <public key file> <plaintext file> <output ciphertext file>"
    print
    "decrypt <private key file> <ciphertext file> <output plaintext file>"
    print
    "sign <private key file> <file to sign> <signature output file>"
    print
    "verify <public key file> <signature file> <file to verify>"
    sys.exit(1)


if len(sys.argv) != 5:
    usage()
elif sys.argv[1] == 'encrypt':
    encrypt(sys.argv[2], sys.argv[3], sys.argv[4])
elif sys.argv[1] == 'decrypt':
    decrypt(sys.argv[2], sys.argv[3], sys.argv[4])
elif sys.argv[1] == 'sign':
    sign(sys.argv[2], sys.argv[3], sys.argv[4])
elif sys.argv[1] == 'verify':
    verify(sys.argv[2], sys.argv[3], sys.argv[4])
else:
    usage()
