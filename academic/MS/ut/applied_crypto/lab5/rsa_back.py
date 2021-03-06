#!/usr/bin/env python3

import codecs, hashlib, os, sys # do not use any other imports/libraries
from pyasn1.codec.der import decoder

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

def pem_to_der(content):
    # converts PEM content to DER
    content = content.replace('-----BEGIN RSA PRIVATE KEY-----','')
    content = content.replace('-----END RSA PRIVATE KEY-----','')
    # content = content.replace("\r", "")
    # content = content.replace("\n", "")
    content = codecs.decode(content.encode(), 'base64')
    return content

def get_pubkey(filename):
    # reads public key file and returns (n, e)

    # decode the DER to get public key DER structure, which is encoded as BITSTRING

    # convert BITSTRING to bytestring

    # decode the bytestring (which is actually DER) and return (n, e)

    return int(pubkey[0]), int(pubkey[1])

def get_privkey(filename):
    # reads private key file and returns (n, d)

    return int(privkey[0][1]), int(privkey[0][3])


def pkcsv15pad_encrypt(plaintext, n):
    # pad plaintext for encryption according to PKCS#1 v1.5

    # calculate number of bytes required to represent the modulus n

    # plaintext must be at least 11 bytes smaller than the modulus

    # generate padding bytes
    return padded_plaintext

def pkcsv15pad_sign(plaintext, n):
    # pad plaintext for signing according to PKCS#1 v1.5

    # calculate byte length of modulus n

    # plaintext must be at least 3 bytes smaller than modulus

    # generate padding bytes
    return padded_plaintext

def pkcsv15pad_remove(plaintext):
    # removes PKCS#1 v1.5 padding

    return plaintext

def encrypt(keyfile, plaintextfile, ciphertextfile):

    pass

def decrypt(keyfile, ciphertextfile, plaintextfile):
    pass

def digestinfo_der(filename):
    # returns ASN.1 DER encoded DigestInfo structure containing SHA256 digest of file
    return der

def sign(keyfile, filetosign, signaturefile):
    pass

    # Warning: make sure that signaturefile produced has the same
    # length as the modulus (hint: use parametrized nb()).

def verify(keyfile, signaturefile, filetoverify):
    # prints "Verified OK" or "Verification failure"
    pass

def usage():
    print "Usage:"
    print "encrypt <public key file> <plaintext file> <output ciphertext file>"
    print "decrypt <private key file> <ciphertext file> <output plaintext file>"
    print "sign <private key file> <file to sign> <signature output file>"
    print "verify <public key file> <signature file> <file to verify>"
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
