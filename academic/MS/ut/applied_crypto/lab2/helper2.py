#!/usr/bin/env python
import sys   # do not use any other imports/libraries

# took x.y hours (please specify here how much time your solution required)
import sys, os, hashlib, traceback, codecs

_type_class_universal = 0
_type_class_application = 1 << 6
_type_class_context_defined = 2 << 6
_type_class_context_private = 3 << 6

_type_form_primitive = 0 << 5
_type_form_constructed = 1 << 5

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
    if len(value_bytes) < 128:
        b = bytes([len(value_bytes)])
    else:
        integer_to_encode_as_byte = nb(len(value_bytes))
        b = bytes([(1<<7 | len(integer_to_encode_as_byte))]) + integer_to_encode_as_byte
    return b

def asn1_len_m(value_bytes):
    # helper function - should be used in other functions to calculate length octet(s)
    # value_bytes - bytes containing TLV value byte(s)
    # returns length (L) byte(s) for TLV
    if len(value_bytes) < 128:
        return bytes([len(value_bytes)])
    else:
        b = nb(len(value_bytes))
        c = 1
        c = c << 7
        c = c | len(b)
        c = bytes([c])
        return c + b


def asn1_boolean(bool):
    # BOOLEAN encoder has been implemented for you
    if bool:
        bool = b'\xff'
    else:
        bool = b'\x00'
    return bytes([0x01]) + asn1_len(bool) + bool

b = bytes([1])
for i in range(1, 1027):
    b = b + bytes([0])
print("======= code by forhad =====")
print(len(b))
print(bin(asn1_len(b)[0]))
print(bin(asn1_len(b)[1]))
print(bin(asn1_len(b)[2]))
# print(asn1_boolean(0x00))
print("===by  mikk====")
print(len(b))
print(bin(asn1_len_m(b)[0]))
print(bin(asn1_len_m(b)[1]))
print(bin(asn1_len_m(b)[2]))
# print(asn1_boolean(0x00))


# print("===================")
# for x in asn1_boolean(0xff):
#     print(bin(x))