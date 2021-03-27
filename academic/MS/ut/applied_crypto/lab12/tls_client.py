#!/usr/bin/env python3

import argparse, codecs, hmac, socket, sys, time, os, datetime
from hashlib import sha1, sha256
from Crypto.Cipher import ARC4
from pyasn1.codec.der import decoder  # do not use any other imports/libraries
from urllib.parse import urlparse

# took x.y hours (please specify here how much time your solution required)

# parse arguments
parser = argparse.ArgumentParser(description='TLS v1.2 client')
parser.add_argument('url', type=str, help='URL to request')
parser.add_argument('--certificate', type=str, help='File to write PEM-encoded server certificate')
args = parser.parse_args()

def get_pubkey_certificate(cert):
    # reads the certificate and returns (n, e)
    # f = open('key.out','wb')
    # f.write(cert)
    # f.close()
    pubkey = [0, 0]
    # keyfile = open(filename, 'rb')
    # decode the DER to get public key DER structure, which is encoded as BITSTRING
    # der = pem_to_der(keyfile.read())
    der = cert
    bitstring = str(decoder.decode(der)[0][1])
    # convert BITSTRING to bytestring
    privkey = decoder.decode(der)


    kfc = str(privkey[0][0][6][1])
    return int(kfc,2)
   # kbc = bytes(int(kfc[i: i + 8], 2) for i in range(0, len(bitstring), 8))

    #return int(privkey[0][1]), int(privkey[0][3])

    #
    # bytestring = bytes(int(bitstring[i: i + 8], 2) for i in range(0, len(bitstring), 8))
    # pubkey[0] = decoder.decode(bytestring)[0][0]
    # pubkey[1] = decoder.decode(bytestring)[0][1]
    # return int(pubkey[0]), int(pubkey[1])

def pkcsv15pad_encrypt(plaintext, n):
    # pad plaintext for encryption according to PKCS#1 v1.5

    # calculate byte size of modulus n
    k = (n.bit_length()+7)//8

    # plaintext must be at least 11 bytes smaller than modulus
    if len(plaintext) > (k - 11):
        print("[-] Plaintext larger than modulus - 11 bytes")
        sys.exit(1)

    # generate padding bytes
    padding_len = k - len(plaintext) - 3
    padding = b""
    for i in range(padding_len):
        padbyte = os.urandom(1)
        while padbyte==b"\x00":
            padbyte = os.urandom(1)
        padding += padbyte

    return b"\x00\x02" + padding + b"\x00" + plaintext

def rsa_encrypt(cert, m):
    # encrypts message m using public key from certificate cert
    n, e = get_pubkey_certificate(cert)
    m = pkcsv15pad_encrypt(m, n)
    m = bn(m)
    c = pow(m, e, n)
    c = nb(c, (n.bit_length()+7)//8)
    return c

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

SSL_VERSION = b"\x03\x01"
HANDSHAKE = b"\x16"
# returns TLS record that contains ClientHello handshake message
def client_hello():
    global client_random, handshake_messages

    print("--> ClientHello()")
    # list of cipher suites the client supports
    csuite = b"\x00\x05"  # TLS_RSA_WITH_RC4_128_SHA
    # csuite += b"\x00\x2f"  # TLS_RSA_WITH_AES_128_CBC_SHA
    # csuite += b"\x00\x35"  # TLS_RSA_WITH_AES_256_CBC_SHA

    # add Handshake message header
    client_random = b"\xAB" * 32
    # print("Client random: %s" % client_random.encode("hex"))
    CLIENT_HELLO = b"\x01"
    client_version = SSL_VERSION
    unix_time = nb(int(time.time()))
    random_bytes = os.urandom(28)  # client_random[4:]
    session_id_len = b"\x00"
    session_id = b""
    cipher_suites_len = nb(2, 2)  # only TLS_DHE_RSA_WITH_AES_256_CBC_SHA
    compression_method_len = b"\x01"
    compression_method = b"\x00"  # no compression
    # add record layer header
    client_hello_data = (b'\x03\x03' + unix_time + random_bytes +
                         session_id_len + session_id + cipher_suites_len +
                         csuite +
                         compression_method_len + compression_method)
    client_hello_tlv = CLIENT_HELLO + nb(len(client_hello_data), 3) + client_hello_data
    record = HANDSHAKE + SSL_VERSION + nb(len(client_hello_tlv), 2) + client_hello_tlv
    return record

# returns TLS record that contains ClientKeyExchange message containing encrypted pre-master secret
def client_key_exchange():
    global server_cert, premaster, handshake_messages

    premaster = os.urandom(48)
    n, e = get_pubkey_certificate(server_cert)

    client_key_exchange_tlv = b'\x10'
    record = HANDSHAKE + SSL_VERSION + nb(len(client_key_exchange_tlv), 2) + client_key_exchange_tlv
    print("--> ClientKeyExchange()")

    return record

# returns TLS record that contains ChangeCipherSpec message
def change_cipher_spec():
    print("--> ChangeCipherSpec()")

    return record

# returns TLS record that contains encrypted Finished handshake message
def finished():
    global handshake_messages, master_secret

    print("--> Finished()")
    client_verify = PRF(master_secret, b"client finished" + sha256(handshake_messages).digest(), 12)

    return record

# returns TLS record that contains encrypted Application data
def application_data(data):
    print("--> Application_data()")
    print(data.decode().strip())

    return record

# parse TLS Handshake messages
def parsehandshake(r):
    global server_hello_done_received, server_random, server_cert, handshake_messages, server_change_cipher_spec_received, server_finished_received

    # decrypt if encryption enabled
    if server_change_cipher_spec_received:
        r = decrypt(r, b"\x16", b"\x03\x03")

    # read Handshake message type and length from message header
    htype, hlength = r[0:1], bn(r[1:4])

    body = r[4:4+hlength]
    handshake = r[:4+hlength]
    handshake_messages+= handshake

    if htype == b"\x02":
        print("	<--- ServerHello()")
        printServerHelloData(r)
    elif htype == b"\x0b":
        print("	<--- Certificate()")
        printServerCertificateData(r)
    elif htype == b"\x0e":
        print("	<--- ServerHelloDone()")
        server_hello_done_received = True
    elif htype == b"\x14":
        print("	<--- Finished()")
        # hashmac of all Handshake messages except the current Finished message (obviously)
        verify_data_calc = PRF(master_secret, b"server finished" + sha256(handshake_messages[:-4-hlength]).digest(), 12)
        if server_verify!=verify_data_calc:
            print("[-] Server finished verification failed!")
            sys.exit(1)
    else:
        print("[-] Unknown Handshake Type:", htype.hex())
        sys.exit(1)

    # handle the case of several Handshake messages in one record
    leftover = r[4+len(body):]
    if len(leftover):
        parsehandshake(leftover)

# parses TLS record
def parserecord(r):
    global server_change_cipher_spec_received

    # parse TLS record header and pass the record body to the corresponding parsing method
    ctype = r[0:1]
    c = r[5:]

    # handle known types
    if ctype == b"\x16":
        print("<--- Handshake()")
        parsehandshake(c)
    elif ctype == b"\x14":
        print("<--- ChangeCipherSpec()")
        server_change_cipher_spec_received = True
    elif ctype == b"\x15":
        print("<--- Alert()")
        level, desc = c[0], c[1]
        if level == 1:
            print("	[-] warning:", desc)
        elif level == 2:
            print("	[-] fatal:", desc)
            sys.exit(1)
        else:
            sys.exit(1)
    elif ctype == b"\x17":
        print("<--- Application_data()")
        data = decrypt(c, b"\x17", b"\x03\x03")
        print(data.decode().strip())
    else:
        print("[-] Unknown TLS Record type:", ctype.hex())
        sys.exit(1)

def printServerHelloData(r):
    header = {
    }
    body =  (r[4:])  # recv_num_bytes(s, length)
    version = body[:2]
    server_randomness = body[2: 2 + 32]
    timestamp = server_randomness[:4]
    session_id_len_b = body[34:35]
    session_id_len = bn(session_id_len_b)
    session_id = body[35: 35 + session_id_len]
    cipher_suit = body[35 + session_id_len: 35 + session_id_len + 2]
    compression_method = body[35 + session_id_len + 2: 35 + session_id_len + 2 + 1]
    extensions = body[35 + session_id_len + 2 + 1:]
    header['server_random'] = server_randomness
    header['gmt'] = datetime.datetime.fromtimestamp(bn(timestamp)).strftime('%Y-%m-%d %H:%M:%S')
    header['sessid'] = session_id
    header['cipher'] = cipher_suit
    header['compression'] = bn(compression_method)
    server_random = header['server_random']
    gmt = header['gmt']
    sessid = header['sessid']
    cipher = header['cipher']
    compression = header['compression']

    print("	[+] server randomness:", server_random.hex().upper())
    print("	[+] server timestamp:", gmt)
    print("	[+] TLS session ID:", sessid.hex().upper())

    cipher = cipher_suit
    if cipher == b"\x00\x2f":
        print("	[+] Cipher suite: TLS_RSA_WITH_AES_128_CBC_SHA")
    elif cipher == b"\x00\x35":
        print("	[+] Cipher suite: TLS_RSA_WITH_AES_256_CBC_SHA")
    elif cipher == b"\x00\x05":
        print("	[+] Cipher suite: TLS_RSA_WITH_RC4_128_SHA")
    else:
        print("[-] Unsupported cipher suite selected:", cipher.hex())

def printServerCertificateData(r):
    global server_cert
    header = {
    }
    certificate_field_len = bn(r[1:4])
    certificates_len =  bn(r[4:7])
    certificates = []
    cert_string_left = r[7:certificates_len+7]
    while cert_string_left:
        cert_len = bn(cert_string_left[:3])
        certificates.append(cert_string_left[3: 3 + cert_len])
        cert_string_left = cert_string_left[3 + cert_len:]
    header['certlen'] = len(certificates[0])
    server_cert = certificates[0]
    print("[+] Server certificate length: ", len(certificates[0]))
    """"
    # if (certificates_len + 4 + 3 != len(r)):
    #     combined = True
    #     header['combined'] = r[certificates_len + 4 + 3:]
    # if args.certificate:
   
    f = open("key.pem", 'wb')
    cert = certificates[0]
    encoded_hext = codecs.encode(cert, 'hex')
    p = b'-----BEGIN CERTIFICATE-----\n'
    p += codecs.encode(cert, 'base64');
    # p += b'\n'
    p += b'-----END CERTIFICATE-----\n';
    pem = p
    f.write(pem)
    f.close()
    """
# PRF defined in TLS v1.2
def PRF(secret, seed, l):

    out = b""
    A = hmac.new(secret, seed, sha256).digest()
    while len(out) < l:
        out += hmac.new(secret, A + seed, sha256).digest()
        A = hmac.new(secret, A, sha256).digest()
    return out[:l]

# derives master_secret
def derive_master_secret():
    global premaster, master_secret, client_random, server_random
    master_secret = PRF(premaster, b"master secret" + client_random + server_random, 48)

# derives keys for encryption and MAC
def derive_keys():
    global premaster, master_secret, client_random, server_random
    global client_mac_key, server_mac_key, client_enc_key, server_enc_key, rc4c, rc4s

    key_block = PRF(master_secret, b"key expansion" + server_random + client_random, 136)
    mac_size = 20
    key_size = 16
    iv_size = 16

    client_mac_key = key_block[:mac_size]
    server_mac_key = key_block[mac_size:mac_size*2]
    client_enc_key = key_block[mac_size*2:mac_size*2+key_size]
    server_enc_key = key_block[mac_size*2+key_size:mac_size*2+key_size*2]

    rc4c = ARC4.new(client_enc_key)
    rc4s = ARC4.new(server_enc_key)

# HMAC SHA1 wrapper
def HMAC_sha1(key, data):
    return hmac.new(key, data, sha1).digest()

# calculates MAC and encrypts plaintext
def encrypt(plain, type, version):
    global client_mac_key, client_enc_key, client_seq, rc4c

    mac = HMAC_sha1(client_mac_key, nb(client_seq, 8) + type + version + nb(len(plain), 2) + plain)
    ciphertext = rc4c.encrypt(plain + mac)
    client_seq+= 1
    return ciphertext

# decrypts ciphertext and verifies MAC
def decrypt(ciphertext, type, version):
    global server_mac_key, server_enc_key, server_seq, rc4s

    d = rc4s.decrypt(ciphertext)
    mac = d[-20:]
    plain = d[:-20]

    # verify MAC
    mac_calc = HMAC_sha1(server_mac_key, nb(server_seq, 8) + type + version + nb(len(plain), 2) + plain)
    if mac!=mac_calc:
        print("[-] MAC verification failed!")
        sys.exit(1)
    server_seq+= 1
    return plain

# read from the socket full TLS record
def readrecord():
    record = b""

    # read TLS record header (5 bytes)
    for _ in range(5):
        record += s.recv(1)

    # find data length
    datalen = bn(record[3:5])

    # read TLS record body
    for _ in range(datalen):
        record+= s.recv(1)

    return record

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
url = urlparse(args.url)
host = url.netloc.split(':')
if len(host) > 1:
    port = int(host[1])
else:
    port = 443
host = host[0]


path = url.path

client_random = b""	# will hold client randomness
server_random = b""	# will hold server randomness
server_cert = b""	# will hold DER encoded server certificate
premaster = b""		# will hold 48 byte pre-master secret
master_secret = b""	# will hold master secret
handshake_messages = b"" # will hold concatenation of handshake messages

# client/server keys and sequence numbers
client_mac_key = b""
server_mac_key = b""
client_enc_key = b""
server_enc_key = b""
client_seq = 0
server_seq = 0

# client/server RC4 instances
rc4c = b""
rc4s = b""

s.connect((host, port))
s.send(client_hello())

server_hello_done_received = False
server_change_cipher_spec_received = False
server_finished_received = False

while not server_hello_done_received:
    parserecord(readrecord())
    
s.send(client_key_exchange())
s.send(change_cipher_spec())
derive_master_secret()
derive_keys()
s.send(finished())

while not server_finished_received:
    parserecord(readrecord())

s.send(application_data(b"GET / HTTP/1.0\r\n\r\n"))
parserecord(readrecord())

print("[+] Closing TCP connection!")
s.close()
