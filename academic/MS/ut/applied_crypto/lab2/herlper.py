def nb(value_bytes):
    integer_to_encode_as_byte_list = []
    while value_bytes != 0:
        integer_to_encode_as_byte_list.insert(0, value_bytes & 255)
        value_bytes = value_bytes >> 8
    b = bytes(integer_to_encode_as_byte_list)
    return b

def asn1_len(value_bytes):
    # helper function - should be used in other functions to calculate length octet(s)
    # value_bytes - bytes containing TLV value byte(s)
    # returns length (L) byte(s) for TLV
    if value_bytes < 128:
        b = bytes([value_bytes])
    else:
        integer_to_encode_as_byte = nb(value_bytes)
        b = bytes([(1<<7 | len(integer_to_encode_as_byte))]) + integer_to_encode_as_byte
    return b
# print(bin(asn1_len(126)[0]))
# print(bin(asn1_len(127)[0]))
# print(bin(asn1_len(128)[0]), " ", bin(asn1_len(128)[1]))
# print(bin(asn1_len(1027)[0]), " ", bin(asn1_len(1027)[1]), " ", bin(asn1_len(1027)[2]))
#
# print("140: ", bin(nb(140)[0])) #, " ", bin(nb(140)[1]))
# print("140: ", len(nb(140))) #, " ", bin(nb(140)[1]))
print("ASN_INTEGER:")
def asn1_integer(i):
    # i - arbitrary integer (of type 'int' or 'long')
    # returns DER encoding of INTEGER
    integer_to_encode_as_byte = nb(i)
    if((integer_to_encode_as_byte[0] & (1 << 7)) > 0):
            integer_to_encode_as_byte = bytes([0x00]) + integer_to_encode_as_byte
    length = len(integer_to_encode_as_byte)
    return bytes([0x02]) + asn1_len(length) + integer_to_encode_as_byte
print(asn1_integer(140))
for i in asn1_integer(140):
    print(bin(i), end = " ")

print("ASN BITSTRING")


def bin_string_to_int(str):
    val = 0
    power_of_two = 1
    for i in range(len(str) - 1, -1, -1):
        val = val + (ord(str[i]) - 48) * power_of_two
        power_of_two = power_of_two * 2
    return val
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
    return bytes([0x03]) + asn1_len(1 + (byte_len)) + integer_to_encode_as_byte
print(bin_string_to_int('10001010'))
print(bin_string_to_int('00000001'))
print(bin_string_to_int('10000001'))

for i in asn1_bitstring('010101011'):
    print(bin(i), end = " ")

print("OCTATE_STRING")

def asn1_octetstring(octets):
    # octets - arbitrary byte string (e.g., b"abc\x01")
    # returns DER encoding of OCTETSTRING
    return bytes([0x04]) + asn1_len(len(octets)) + octets




print("asn1_octetstring", asn1_octetstring(b"040700686f686f686f"))
for i in asn1_octetstring(b"040700686f686f686f"):
    print(bin(i), end = " ")
# print("asn1_octetstring", [b"\xff"*550], b"04820226"+b"ff"*550)


def asn1_null():
    # returns DER encoding of NULL
    return bytes([0x05]) #+ asn1_len(len(octets)) + octets



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

    return bytes([0x03]) + asn1_len(len(integer_to_encode_as_byte)) + integer_to_encode_as_byte

asn1_objectidentifier([1,2,840])
