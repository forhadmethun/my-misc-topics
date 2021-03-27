#!/usr/bin/env python3

import argparse, codecs, sys     # do not use any other imports/libraries
from smartcard.CardType import AnyCardType
from smartcard.CardRequest import CardRequest
from smartcard.CardConnection import CardConnection
from smartcard.util import toHexString

# took 3.0 hours (please specify here how much time your solution required)

# parse arguments
parser = argparse.ArgumentParser(description='Fetch certificates from ID card', add_help=False)
parser.add_argument('--cert', type=str, default=None, choices=['auth','sign'], help='Which certificate to fetch')
parser.add_argument("--out", required=True, type=str, help="File to store certificate (PEM)")
args = parser.parse_args()


# this will wait for card inserted in any reader
channel = CardRequest(timeout=100, cardType=AnyCardType()).waitforcard().connection
print("[+] Selected reader:", channel.getReader())

# using T=0 for compatibility and simplicity
try:
    channel.connect(CardConnection.T0_protocol)
except:
    # fallback to T=1 if the reader does not support T=0
    channel.connect(CardConnection.T1_protocol)

# detect and print EstEID card type
atr = channel.getATR()
if atr == [0x3B,0xFE,0x18,0x00,0x00,0x80,0x31,0xFE,0x45,0x45,0x73,0x74,0x45,0x49,0x44,0x20,0x76,0x65,0x72,0x20,0x31,0x2E,0x30,0xA8]:
    print("[+] EstEID v3.x on JavaCard")
elif atr == [0x3B,0xFA,0x18,0x00,0x00,0x80,0x31,0xFE,0x45,0xFE,0x65,0x49,0x44,0x20,0x2F,0x20,0x50,0x4B,0x49,0x03]:
    print("[+] EstEID v3.5 (10.2014) cold (eID)")
elif atr == [0x3B,0xDB,0x96,0x00,0x80,0xB1,0xFE,0x45,0x1F,0x83,0x00,0x12,0x23,0x3F,0x53,0x65,0x49,0x44,0x0F,0x90,0x00,0xF1]:
    print("[+] Estonian ID card (2018)")
else:
    print("[-] Unknown card:", toHexString(atr))
    sys.exit(1)

def send(apdu):
    data, sw1, sw2 = channel.transmit(apdu)

    # success
    if [sw1,sw2] == [0x90,0x00]:
        return data
    # (T=0) card signals how many bytes to read
    elif sw1 == 0x61:
        #print("[=] More data to read:", sw2)
        return send([0x00, 0xC0, 0x00, 0x00, sw2]) # GET RESPONSE of sw2 bytes
    # (T=0) card signals incorrect Le
    elif sw1 == 0x6C:
        #print("[=] Resending with Le:", sw2)
        return send(apdu[0:4] + [sw2]) # resend APDU with Le = sw2
    # probably error condition
    else:
        print("Error: %02x %02x, sending APDU: %s" % (sw1, sw2, toHexString(apdu)))
        sys.exit(1)

# reading from the card auth or sign certificate (EstEID spec page 33)
print("[=] Retrieving %s certificate..." % (args.cert))



# read the first 10 bytes to parse ASN.1 length field and determine certificate length
# A000000077010800070000FE00000100
send([0x00, 0xA4, 0x04, 0x00, 0x10, 0xA0, 0x00, 0x00, 0x00, 0x77, 0x01, 0x08, 0x00, 0x07, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x01, 0x00])
send([0x00, 0xA4, 0x00, 0x0C]) # SELECT FILE (MF)
if args.cert == 'auth':
    send([0x00, 0xA4, 0x01, 0x0C] + [0x02, 0xad, 0xf1])  # MF/adf1

    send([0x00, 0xA4, 0x02, 0x0C] + [0x02, 0x34, 0x01])  # MF/adf1/3401

else:
    send([0x00, 0xA4, 0x01, 0x0C] + [0x02, 0xad, 0xf2])  # MF/adf1

    send([0x00, 0xA4, 0x02, 0x0C] + [0x02, 0x34, 0x1f])  # MF/adf1/341f

r = send([0x00, 0xB0, 0x00, 0x00, 0x10])  # READ BINARY

der_t_len = 1
der_l_len = 0
der_v_len = 0
certlen = 0
if(r[1] < 128):
    der_l_len = 1
    der_v_len = r[1]
else:
    seq_len_byte = ~(1 << 7) & r[1]
    der_l_len = seq_len_byte + 1
    for i in range(2, 2 + seq_len_byte):
       der_v_len = der_v_len << 8
       der_v_len = der_v_len | r[i]
certlen = der_t_len + der_l_len + der_v_len

print("[+] Certificate size: %d bytes" % (certlen))

# reading DER encoded certificate from smart card
cert = b''

extra_one = False
if(certlen %2 == 1):
    extra_one = True
    certlen = certlen - 1
i = 0
while i < certlen:
# for i in range(0, certlen, 2):
    msb =  i >> 8
    lsb =  i & 0xff
    r = send([0x00, 0xB0, msb, lsb, 0x2])  # READ BINARY
    cert += bytes(r)
    i = i + 2
if extra_one:
    certlen = certlen
    i = certlen
    msb = i >> 8
    lsb = i & 0xff
    r = send([0x00, 0xB0, msb, lsb, 0x1])  # READ BINARY
    cert += bytes(r)
# save certificate in PEM form
open(args.out,"wb").write(b"-----BEGIN CERTIFICATE-----\n"+codecs.encode(cert, 'base64')+b"-----END CERTIFICATE-----\n")
print("[+] Certificate stored in", args.out)
