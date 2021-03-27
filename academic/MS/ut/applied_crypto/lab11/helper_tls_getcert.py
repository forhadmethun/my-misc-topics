#!/usr/bin/env python3

import argparse, codecs, datetime, os, socket, sys, time  # do not use any other imports/libraries
from urllib.parse import urlparse

# took x.y hours (please specify here how much time your solution required)

# parse arguments
parser = argparse.ArgumentParser(description='TLS v1.2 client')
parser.add_argument('url', type=str, help='URL to request')
parser.add_argument('--certificate', type=str, help='File to write PEM-encoded server certificate')
args = parser.parse_args()


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


SSL_VERSION = b"\x03\x01"
HANDSHAKE = b"\x16"


# returns TLS record that contains ClientHello Handshake message
def client_hello():
    print("--> ClientHello()")

    # list of cipher suites the client supports
    csuite = b"\x00\x05"  # TLS_RSA_WITH_RC4_128_SHA
    csuite += b"\x00\x2f"  # TLS_RSA_WITH_AES_128_CBC_SHA
    csuite += b"\x00\x35"  # TLS_RSA_WITH_AES_256_CBC_SHA

    # add Handshake message header
    client_random = b"\xAB" * 32
    # print("Client random: %s" % client_random.encode("hex"))
    CLIENT_HELLO = b"\x01"
    client_version = SSL_VERSION
    unix_time = nb(int(time.time()))
    random_bytes = os.urandom(28)  # client_random[4:]
    session_id_len = b"\x00"
    session_id = b""
    cipher_suites_len = nb(6, 2)  # only TLS_DHE_RSA_WITH_AES_256_CBC_SHA
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


# returns TLS record that contains 'Certificate unknown' fatal Alert message
def alert():
    print("--> Alert()")

    # add alert message

    # add record layer header
    record = b''  ##del
    alert_ld = b'\x02' + b'\0x2e'
    record = b"\x15" + SSL_VERSION + nb(len(alert_ld), 2) + alert_ld
    return record


# parse TLS Handshake messages
def parsehandshake(r):
    global server_hello_done_received
    # read Handshake message type and length from message header
    htype = r['htype']  ## del
    print("<--- Handshake()")
    if htype == 0x02:
        print("	<--- ServerHello()")
        server_random = r['server_random']
        gmt = r['gmt']
        sessid = r['sessid']
        cipher = r['cipher']
        compression = r['compression']
        print("	[+] server randomness:", server_random.hex().upper())
        print("	[+] server timestamp:", gmt)
        print("	[+] TLS session ID:", sessid.hex().upper())

        if cipher == b"\x00\x2f":
            print("	[+] Cipher suite: TLS_RSA_WITH_AES_128_CBC_SHA")
        elif cipher == b"\x00\x35":
            print("	[+] Cipher suite: TLS_RSA_WITH_AES_256_CBC_SHA")
        elif cipher == b"\x00\x05":
            print("	[+] Cipher suite: TLS_RSA_WITH_RC4_128_SHA")
        else:
            print("[-] Unsupported cipher suite selected:", cipher.hex())
            sys.exit(1)

        if compression != 0x00:
            print("[-] Wrong compression:", compression)
            sys.exit(1)

    elif htype == 0x0b:
        print("	<--- Certificate()")
        certlen = r['certlen']
        print("	[+] Server certificate length:", certlen)
        if args.certificate:
            print("	[+] Server certificate saved in:", args.certificate)
    elif htype == 0x0e:
        print("	<--- ServerHelloDone()")
        server_hello_done_received = True
    else:
        print("[-] Unknown Handshake type:", htype)
        sys.exit(1)

    # handle the case of several handshake messages in one record
    # leftover = ...
    # if len(leftover):
    #     parsehandshake(leftover)


# parses TLS record
def parserecord(r):
    # parse TLS record header and pass the record body to the corresponding parsing method (i.e., parsehandshake())
    # htype = r.htype  ## del
    # server_random = r.server_random
    # gmt = r.gmt
    # sessid = r.sessid
    # cipher = r.cipher
    # compression = r.compression
    # certlen = r.certlen
    header = {

    }
    type = bn(r[:1])  # recv_num_bytes(s, 1)
    header['htype'] = type
    if type == 0x02:
        length_b = r[1:4]
        length = bn(length_b)
        body = (r[4:])  # recv_num_bytes(s, length)
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
    elif type == 0x0b:
        certificate_field_len = bn(r[1:4])
        certificates_len = bn(r[4:7])
        certificates = []
        cert_string_left = r[7: 7 + certificates_len]
        while cert_string_left:
            cert_len = bn(cert_string_left[:3])
            certificates.append(cert_string_left[3: 3 + cert_len])
            cert_string_left = cert_string_left[3 + cert_len:]
        header['certlen'] = len(certificates[0])
        f = open(args.certificate, 'wb')
        cert = certificates[0]
        encoded_hext = codecs.encode(cert, 'hex')
        f.write(cert)
        f.close()

    parsehandshake(header)
    # pass


# read from the socket full TLS record
def recv_num_bytes(s, num):
    ret = b""
    while len(ret) < num:
        ret += s.recv(min(4096, num - len(ret)))
    return ret



def readrecord():
    global s
    record = b""
    # read the TLS record header (5 bytes)
    rec_type = recv_num_bytes(s, 1)
    tls_version = recv_num_bytes(s, 2)
    # find data length
    rec_len_b = recv_num_bytes(s, 2)
    rec_len = bn(rec_len_b)
    # read the TLS record body
    record = recv_num_bytes(s, rec_len)
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

s.connect((host, port))
s.send(client_hello())

server_hello_done_received = False
while not server_hello_done_received:
    parserecord(readrecord())
s.send(alert())
print("[+] Closing TCP connection!")
s.close()
# https://www.eesti.ee/ --certificate server.pem
