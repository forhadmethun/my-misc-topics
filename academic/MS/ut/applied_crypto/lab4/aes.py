#!/usr/bin/python3

import datetime, os, sys
from pyasn1.codec.der import decoder

# $ sudo apt-get install python3-crypto
sys.path = sys.path[1:] # removes script directory from aes.py search path
from Crypto.Cipher import AES          # https://www.dlitz.net/software/pycrypto/api/current/Crypto.Cipher.AES-module.html
from Crypto.Util.strxor import strxor  # https://www.dlitz.net/software/pycrypto/api/current/Crypto.Util.strxor-module.html#strxor
from hashlib import pbkdf2_hmac
import hashlib, hmac # do not use any other imports/libraries

# took 8.5 hours (please specify here how much time your solution required)

_buffer_size = 16
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
def asn1_integer(i):
    # i - arbitrary integer (of type 'int' or 'long')
    # returns DER encoding of INTEGER
    integer_to_encode_as_byte = nb(i)
    if((integer_to_encode_as_byte[0] & (1 << 7)) > 0):
            integer_to_encode_as_byte = bytes([0x00]) + integer_to_encode_as_byte
    return bytes([0x02]) + asn1_len(integer_to_encode_as_byte) + integer_to_encode_as_byte


# this function benchmarks how many PBKDF2 iterations
# can be performed in one second on the machine it is executed
# todo : is the benchmark method okay?
def benchmark():
    temp_password = os.urandom(10)
    PRF = 'sha1'
    # measure time for performing 10000 iterations
    start = datetime.datetime.now()
    key = pbkdf2_hmac(PRF, temp_password, b'abcdefgh', 10000, 36)

    stop = datetime.datetime.now()
    time = (stop - start).total_seconds()
    iter = int ( 10000 / time )

    print("[+] Benchmark: %s PBKDF2 iterations in 1 second" % (iter))

    return iter # returns number of iterations that can be performed in 1 second


def encrypt(pfile, cfile):
    # benchmarking
    iter = benchmark()
    # asking for password
    password = input("[?] Enter password: ").encode()
    PRF = 'sha1'
    salt = os.urandom(8)
    key = pbkdf2_hmac(PRF, password, salt, iter, 36)
    key_aes = b''
    key_hmac = b''
    key_aes = key[0:16]
    key_hmac = key[16:]

    hmac_object  = hmac.new(key_hmac, b'', hashlib.sha1)#hashlib.sha256
    iv_current = os.urandom(16)
    iv_initialize = iv_current

    cipher = AES.new(key_aes)
    # writing ciphertext in temporary file and calculating HMAC digest
    myfile = open(pfile + ".tmp", "wb")
    with open(pfile, 'rb') as f:
        last = False
        while True:
            data = f.read(_buffer_size)
            if not data:
                break
            rem = len(data) % 16
            if(rem!=0):
                data += bytes([16 - rem]) * (16 - rem)
                last = True

            encrypted_data = cipher.encrypt(strxor(data, iv_current))
            myfile.write(encrypted_data)
            hmac_object.update(encrypted_data)
            iv_current = encrypted_data
        if last == False:
            data = bytes([16]) * 16
            encrypted_data = cipher.encrypt(strxor(data, iv_current))
            myfile.write(encrypted_data)
            hmac_object.update(encrypted_data)
            iv_current = encrypted_data

    myfile.close()
    message = hmac_object.digest()
    # writing DER structure in cfile
    asn1 = asn1_sequence(
            asn1_sequence(
                asn1_octetstring(salt)
                + asn1_integer(iter)
                + asn1_integer(36)
            )
            +
            asn1_sequence(
                 asn1_objectidentifier([2, 16, 840, 1, 101, 3, 4, 1, 2])
                 +
                 asn1_octetstring(iv_initialize)
            )
            +
            asn1_sequence(
                asn1_sequence(
                    asn1_objectidentifier([1, 3, 14, 3, 2, 26])
                    + asn1_null()
                )
                +
                asn1_octetstring(message)
            )
        )
    # writing temporary ciphertext file to cfile
    cipher_file = open(cfile, 'wb')
    cipher_file.write(asn1)
    with open(pfile +".tmp", 'rb') as f:
        while True:
            data = f.read(_buffer_size)
            if not data:
                break
            cipher_file.write(data)
    cipher_file.close()
    os.unlink(pfile +".tmp")


def decrypt(cfile, pfile):
    first_ten_bytes = b''
    with open(cfile, 'rb') as f:
        first_ten_bytes = f.read(10)
    der_len = (first_ten_bytes[1])
    ln = der_len
    if((der_len & 1 << 7) > 0) :
        byte_need_to_read = (der_len ^ 1 << 7)
        dl = ''
        it = 2
        temp_byte_need_to_read = byte_need_to_read
        while byte_need_to_read > 0:
            str = int_to_bin_string(int(first_ten_bytes[it]))
            while(len(str)!=8):
                str = '0' + str
            dl += str
            it+=1
            byte_need_to_read-=1
        ln = bin_string_to_int(dl)
        ln+=temp_byte_need_to_read
    ln += 2
    der_len = ln



    # reading DER structure
    digest_calculated = b''
    digest = b''
    der = open(cfile, 'rb').read(der_len)
    digest = bytes(decoder.decode(der)[0][2][1])


    digest_mod = hashlib.sha1
    digest_mod = hashlib.sha1
    digest_type = "HMAC-SHA1"

    # asking for password
    password = input("[?] Enter password: ").encode()
    PRF = 'sha1'
    salt = bytes(decoder.decode(der)[0][0][0]) # b'' # get from the der encoding
    iter = (decoder.decode(der)[0][0][1]) #b'' # get from der encoding
    # derieving key
    key = pbkdf2_hmac(PRF, password, salt, iter, 36)
    key_aes = b''
    key_hmac = b''
    key_aes = key[0:16]
    key_hmac = key[16:]

    iv_initialize =  (decoder.decode(der)[0][1][1])  # get from der encoding
    iv_current = iv_initialize

    hmac_object = hmac.new(key_hmac, b'', digest_mod)

    # first pass over ciphertext to calculate and verify HMAC
    offset = der_len
    with open(cfile, 'rb') as f:
        f.seek(offset)
        while True:
            data = f.read(_buffer_size)
            if not data:
                break
            hmac_object.update(data)
    digest_calculated = hmac_object.digest()

    if digest_calculated != digest:
        print("[-] HMAC verification failure: wrong password or modified ciphertext!")
        return

    # second pass over ciphertext to decrypt

    cipher = AES.new(key_aes)

    # writing ciphertext in temporary file and calculating HMAC digest
    output_file = open(pfile, 'wb')
    with open(cfile, 'rb') as f:
        f.seek(offset)
        last = False
        prev_data = b''
        while True:
            data = f.read(_buffer_size)
            if not data:
                break
            if prev_data:
                encrypted_data = strxor(cipher.decrypt(prev_data), bytes(iv_current))
                output_file.write(encrypted_data)
                iv_current = prev_data
            prev_data = data

        encrypted_data = strxor(cipher.decrypt(prev_data), bytes(iv_current))
        last_block = encrypted_data[0:16 - int(encrypted_data[-1])]
        output_file.write(last_block)
    output_file.close()


def usage():
    print("Usage:")
    print("-encrypt <plaintextfile> <ciphertextfile>")
    print("-decrypt <ciphertextfile> <plaintextfile>")
    sys.exit(1)


if len(sys.argv) != 4:
    usage()
elif sys.argv[1] == '-encrypt':
    encrypt(sys.argv[2], sys.argv[3])
elif sys.argv[1] == '-decrypt':
    decrypt(sys.argv[2], sys.argv[3])
else:
    usage()
