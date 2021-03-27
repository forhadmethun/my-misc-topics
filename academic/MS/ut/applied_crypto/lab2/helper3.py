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

def asn1_objectidentifier(oid):
    # oid - list of integers representing OID (e.g., [1,2,840,123123])
    # returns DER encoding of OBJECTIDENTIFIER
    integer_to_encode_as_byte = b''
    last = True
    for i in range(len(oid) - 1, 1, -1):
        int_list = []
        # bitstr = int_to_bin_string(oid[i])
        x = oid[i]
        while x != 0:
            if last is False:
                mask = x & 127
                mask = mask | (1 << 7)
            else:
                mask = x & 127
                last = False

            int_list.insert(0, mask)
            x >>= 6
        integer_to_encode_as_byte = bytes(int_list) + integer_to_encode_as_byte
    integer_to_encode_as_byte = bytes([oid[0] * 40 + oid[1]]) + integer_to_encode_as_byte

    return bytes([0x6]) + asn1_len((integer_to_encode_as_byte)) + integer_to_encode_as_byte
p =  asn1_objectidentifier([1,2,840])
# print(p)
for x in p:
    print(bin(x))