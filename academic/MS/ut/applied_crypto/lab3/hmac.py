#!/usr/bin/python3

import codecs, hashlib, sys
from pyasn1.codec.der import decoder
sys.path = sys.path[1:] # don't remove! otherwise the library import below will try to import your hmac.py
import hmac # do not use any other imports/libraries

# took 2.0 hours (please specify here how much time your solution required)
_buffer_size = 512
_type_form_constructed = 1 << 5
def asn1_sequence(der):
    # der - DER bytes to encapsulate into sequence
    # returns DER encoding of SEQUENCE
    return bytes([0x10|_type_form_constructed]) + asn1_len((der)) + der


def asn1_len(value_bytes):
    # helper function - should be used in other functions to calculate length octet(s)
    # value_bytes - bytes containing TLV value byte(s)
    # returns length (L) byte(s) for TLV
    if len(value_bytes) < 128:
        b = bytes([len(value_bytes)])
    else:
        integer_to_encode_as_byte = nb(len(value_bytes))
        b = bytes([(1<<7 | len(integer_to_encode_as_byte))]) + integer_to_encode_as_byte
    return b
def nb(value_bytes):
    integer_to_encode_as_byte_list = []
    if(value_bytes == 0):
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
        if bit =='1':
            i |= 1
    return i

def int_to_bin_string(int):
    if(int == 0):
        return '0'
    val = ''
    while(int != 0):
        val = (chr( (int % 2) + 48) ) + val
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
            if(j == len(str_list) -1 ):
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



def verify(filename):
    print("[+] Reading HMAC DigestInfo from", filename+".hmac")
    digest_calculated = b''
    digest = b''
    der = open(filename+".hmac", 'rb').read()
    digest = bytes(decoder.decode(der)[0][1])
    digest_mod = hashlib.sha256
    digest_type = ""
    format = str(decoder.decode(der)[0][0][0])
    if(format == '2.16.840.1.101.3.4.2.1'):
        digest_type = "HMAC-SHA256"
        digest_mod = hashlib.sha256

    elif format == '1.3.14.3.2.26':
        digest_mod = hashlib.sha1
        digest_type = "HMAC-SHA1"

    elif format == '1.2.840.113549.2.5':
        digest_mod = hashlib.md5
        digest_type = "HMAC-MD5"
    print("[+] " + digest_type + " digest: " +  codecs.encode(digest,'hex').decode())
    key = input("[?] Enter key: ").encode()
    hmac_object  = hmac.new(key, b'', digest_mod)
    with open(filename, 'rb') as f:
        while True:
            data = f.read(_buffer_size)
            if not data:
                break
            hmac_object.update(data)
    digest_calculated = hmac_object.digest()
    print("[+] Calculated " + digest_type + " digest: " + codecs.encode( digest_calculated,'hex').decode())

    if digest_calculated != digest:
        print("[-] Wrong key or message has been manipulated!")
    else:
        print("[+] HMAC verification successful!")

def mac(filename):
    key = input("[?] Enter key: ").encode()
    hmac_object  = hmac.new(key, b'', hashlib.sha256)#hashlib.sha256
    with open(filename, 'rb') as f:
        while True:
            data = f.read(_buffer_size)
            if not data:
                break
            # md5.update(data)
            # sha1.update(data)
            # sha256.update(data)
            hmac_object.update(data)
    message = hmac_object.digest()
    print("[+] Calculated " + "HMAC-SHA256" + " digest: " + codecs.encode( message,'hex').decode())
    print("[+] Writing HMAC DigestInfo to", filename+".hmac")
    asn1 = asn1_sequence(
            asn1_sequence(
                 asn1_objectidentifier([2, 16, 840, 1, 101, 3, 4, 2, 1])# 2.16.840.1.101.3.4.2.1
                + asn1_null()
            )
            + asn1_octetstring(message)
        )
    hmac_filename = open(filename+".hmac", 'wb')
    hmac_filename.write(asn1)


def usage():
    print("Usage:")
    print("-verify <filename>")
    print("-mac <filename>")
    sys.exit(1)

if len(sys.argv) != 3:
    usage()
elif sys.argv[1] == '-mac':
    mac(sys.argv[2])
elif sys.argv[1] == '-verify':
    verify(sys.argv[2])
else:
    usage()
