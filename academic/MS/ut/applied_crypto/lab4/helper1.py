#!/usr/bin/python3

import datetime, os, sys
from pyasn1.codec.der import decoder

# $ sudo apt-get install python3-crypto
sys.path = sys.path[1:] # removes script directory from aes.py search path
from Crypto.Cipher import AES          # https://www.dlitz.net/software/pycrypto/api/current/Crypto.Cipher.AES-module.html
from Crypto.Util.strxor import strxor  # https://www.dlitz.net/software/pycrypto/api/current/Crypto.Util.strxor-module.html#strxor
from hashlib import pbkdf2_hmac
import hashlib, hmac # do not use any other imports/libraries

# took x.y hours (please specify here how much time your solution required)

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
    # print("--: ", i)
    integer_to_encode_as_byte = nb(i)
    if((integer_to_encode_as_byte[0] & (1 << 7)) > 0):
            integer_to_encode_as_byte = bytes([0x00]) + integer_to_encode_as_byte
    # length = len(integer_to_encode_as_byte)
    return bytes([0x02]) + asn1_len(integer_to_encode_as_byte) + integer_to_encode_as_byte


# this function benchmarks how many PBKDF2 iterations
# can be performed in one second on the machine it is executed
# todo : is the benchmark method okay?
def benchmark():
    temp_password = os.urandom(10)
    PRF = 'sha1'
    # measure time for performing 10000 iterations
    start = datetime.datetime.now()
    # for i in range(0, 10000):
    #     pass
    key = pbkdf2_hmac(PRF, temp_password, b'abcdefgh', 10000, 36)

    stop = datetime.datetime.now()
    time = (stop - start).total_seconds()
    # extrapolate to 1 second
    print(time)
    iter = int ( 10000 / time )

    print("[+] Benchmark: %s PBKDF2 iterations in 1 second" % (iter))

    return iter # returns number of iterations that can be performed in 1 second


def encrypt(pfile, cfile):
    # benchmarking
    iter = benchmark()
    # asking for password
    password = input("[?] Enter password: ").encode()
    # temp_password = password
    PRF = 'sha1'

    # deriving key
    # todo what is this?
    # salt = ''
    # salt = hashlib.sha256(os.urandom(60)).hexdigest().encode('ascii')
    salt = os.urandom(8)
    # kLen = _buffer_size
    # key = PBKDF2(PRF, Password, Salt, iter, kLen)
    #todo : does the iter is return value of the benchmark method?
    #todo: should I return the salt as just os.urandom(8)
    #todo: what is PRF? is it 'sha1' ?
    #todo: from slide 16 as AES-128 & 20 as hmac-sha1. what's the purpose of this 36? do we need to do anything with this one?
    key = pbkdf2_hmac(PRF, password, salt, iter, 36)
    key_aes = b''
    key_hmac = b''
    # count = 0
    # for key_byte in key:
    #     if count < 16:
    #         key_aes += bytes([key_byte])
    #     else:
    #         key_hmac += bytes([key_byte])
    #     count+=1

    key_aes = key[0:16]
    key_hmac = key[16:]

    # print(key_aes)
    #todo: does the pbkdf2_hmac method return the key_aes?(yes)(done)

    #todo: do we need to generate hmac with the generated key as previous?
    hmac_object  = hmac.new(key_hmac, b'', hashlib.sha1)#hashlib.sha256

    #todo: does the iv_current  okay?
    iv_current = os.urandom(16)
    iv_initialize = iv_current

    #todo: does the cipher of the following line okay?
    cipher = AES.new(key_aes)


    # writing ciphertext in temporary file and calculating HMAC digest
    myfile = open(pfile + ".tmp", "wb")
    with open(pfile, 'rb') as f:
        last = False
        while True:
            data = f.read(_buffer_size)
            #todo: do i need to padding here? with pkcs #5?
            if not data:
                break
            rem = len(data) % 16
            # if(rem == 0):
            #     data += bytes([5]) * 16
            if(rem!=0):
                data += bytes([16 - rem]) * (16 - rem)
                last = True

            # str_list = [data[i: i + 16] for i in range(0, len(data), 16)]

            # todo : is it okay that I returned the data to the encrypted_data variable?
            # for each_str in str_list:
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


            # hmac_object.update(encrypted_data)

            # todo: is it okay that I updated the iv_current variable for CBC ?
            # iv_current = encrypted_data
            # hmac_object.update(data)
    myfile.close()
    # with open(pfile +".tmp", 'rb') as f:
    #     while True:
    #         data = f.read(_buffer_size)
    #         if not data:
    #             break
    #         hmac_object.update(data)
    message = hmac_object.digest()


    # writing DER structure in cfile
    #todo how ??
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
    cipher_file = open(cfile, 'wb') # todo: is it okay?
    cipher_file.write(asn1)

    # with open(cfile, "ab") as myfile:
    with open(pfile +".tmp", 'rb') as f:
        while True:
            data = f.read(_buffer_size)
            # todo: do i need to padding here? with pkcs #5?
            if not data:
                break
            # myfile.write(data)
            cipher_file.write(data)
    cipher_file.close()
    # todo: where to create the temp file
    # deleting temporary ciphertext file
    # # pass
    os.unlink(pfile +".tmp")


def decrypt(cfile, pfile):
    first_ten_bytes = b''
    #todo how to do that? asn1.seq from bytes??
    with open(cfile, 'rb') as f:
        first_ten_bytes = f.read(10)
    # i = 0
    der_len = (first_ten_bytes[1])
    ln = der_len
    if((der_len & 1 << 7) > 0) :
        # der_len += (der_len & 1 << 7)
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
    # print("[+] Reading HMAC DigestInfo from", filename + ".hmac")
    # todo : what will be the first 10 bytes?
    # todo : what is - Calculate the length of the DER header by parsing the length byte(s) of header???s outer ASN.1 SEQUENCE (all possible sizes of DER header must be handled
    digest_calculated = b''
    digest = b'' #todo : get from the der encoding
    der = open(cfile, 'rb').read(der_len)
    digest = bytes(decoder.decode(der)[0][2][1])


    digest_mod = hashlib.sha1
    # digest_type = ""

    # format = str(decoder.decode(der)[0][0][0])
    # if (format == '2.16.840.1.101.3.4.2.1'):
    #     digest_type = "HMAC-SHA256"
    #     digest_mod = hashlib.sha256
    #
    # elif format == '1.3.14.3.2.26':
    digest_mod = hashlib.sha1
    digest_type = "HMAC-SHA1"

    # elif format == '1.2.840.113549.2.5':
    #     digest_mod = hashlib.md5
    #     digest_type = "HMAC-MD5"
    # print("[+] " + digest_type + " digest: " + codecs.encode(digest, 'hex').decode())


    # asking for password
    # key = input("[?] Enter password: ").encode()

    password = input("[?] Enter password: ").encode()

    PRF = 'sha1'
    salt = bytes(decoder.decode(der)[0][0][0]) # b'' #todo: get from the der encoding
    iter = (decoder.decode(der)[0][0][1]) #b'' #todo : get from der encoding
    #start
    key = pbkdf2_hmac(PRF, password, salt, iter, 36)
    key_aes = b''
    key_hmac = b''
    # count = 0
    # for key_byte in key:
    #     if count < 16:
    #         key_aes += bytes([key_byte])
    #     else:
    #         key_hmac += bytes([key_byte])
    #     count+=1
    key_aes = key[0:16]
    key_hmac = key[16:]
    # print(key_aes)

    iv_initialize =  (decoder.decode(der)[0][1][1])  #todo : get from der encoding
    iv_current = iv_initialize
    #end


    hmac_object = hmac.new(key_hmac, b'', digest_mod)
    # todo: how to derieve keys?
    # derieving key

    # first pass over ciphertext to calculate and verify HMAC
    offset = der_len  # todo : generate from der structure
    with open(cfile, 'rb') as f:
        f.seek(offset)
        while True:
            data = f.read(_buffer_size)
            if not data:
                break
            hmac_object.update(data)
    digest_calculated = hmac_object.digest()
    # print("[+] Calculated " + digest_type + " digest: " + codecs.encode(digest_calculated, 'hex').decode())

    if digest_calculated != digest:
        print("[-]  HMAC verification failure: wrong password or modified ciphertext!")
        return

    # else:
    #     print("[+] HMAC verification successful!")


    # todo what is second pass?
    # second pass over ciphertext to decrypt
    #

    cipher = AES.new(key_aes)

    # writing ciphertext in temporary file and calculating HMAC digest
    output_file = open(pfile, 'wb')
    with open(cfile, 'rb') as f:
        f.seek(offset)
        # last = f.read()
        last = False
        prev_data = b''
        while True:
            data = f.read(_buffer_size)
            # todo: do i need to padding here? with pkcs #5?
            if not data:
                break
            # rem = len(data) % 16
            # if (rem == 0):
            #     data += bytes([5]) * 16
            # else:
            #     data += bytes([5]) * (16 - rem)
            # str_list = [data[i: i + 16] for i in range(0, len(data), 16)]
            # todo : is it okay that I returned the data to the encrypted_data variable?
            # last_str = ''
            # for each_str in str_list:
                # encrypted_data = cipher.encrypt(strxor(each_str, iv_current))

            if prev_data:
                encrypted_data = strxor(cipher.decrypt(prev_data), bytes(iv_current))
                # with open(pfile, "ab") as myfile:
                #     myfile.write(encrypted_data)
                output_file.write(encrypted_data)
                iv_current = prev_data # todo : which one right? the line I wrote or iv_current = each_str!!!!!!!!!
            prev_data = data
            # hmac_object.update(encrypted_data)
            # todo: is it okay that I updated the iv_current variable for CBC ?
            # iv_current = encrypted_data
            # hmac_object.update(data)
        # if(len(prev_data) != 16):
        encrypted_data = strxor(cipher.decrypt(prev_data), bytes(iv_current))
        last_block = encrypted_data[0:16 - int(encrypted_data[-1])]
        # for i in range(0, 16 - int(encrypted_data[-1])):
        #     last_block +=encrypted_data[i]
        output_file.write(last_block)

    output_file.close()

    # # pass

# encrypt('/home/f/Code/Others/general-topics/cyber-security/applied_crypto/lab3/plain','/home/f/Code/Others/general-topics/cyber-security/applied_crypto/lab3/plain.enc')
# decrypt('/home/f/Code/Others/general-topics/cyber-security/applied_crypto/lab3/plain.enc', '/home/f/Code/Others/general-topics/cyber-security/applied_crypto/lab3/plain.new')
decrypt('/home/f/Code/Others/general-topics/cyber-security/applied_crypto/lab4/big.enc', '/home/f/Code/Others/general-topics/cyber-security/applied_crypto/lab4/big')

def usage():
    print("Usage:")
    print("-encrypt <plaintextfile> <ciphertextfile>")
    print("-decrypt <ciphertextfile> <plaintextfile>")
    sys.exit(1)

#
# if len(sys.argv) != 4:
#     usage()
# elif sys.argv[1] == '-encrypt':
#     encrypt(sys.argv[2], sys.argv[3])
# elif sys.argv[1] == '-decrypt':
#     decrypt(sys.argv[2], sys.argv[3])
# else:
#     usage()
