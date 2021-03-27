#!/usr/bin/env python3
import os, sys       # do not use any other imports/libraries
# took x.y hours (please specify here how much time your solution required)
"""
### Time Taken

To solve the problem it took around - 4.5 hours for me. I didn't code in python language for a long time and more specifically I didn't know much about how to read, write byte to file and encode, decode them. Thanks for the slide from where I got almost all the knowledge. 

### Suggestions
 - It would be great if you can form a group in any media like - slack/ skype group/ mail thread/ telegram messenger group, fb messenger group, or anything else,  with all the students who took the cryptography course and including you, as many of us probably facing simple issue/ questions, so we can communicate through the group. Probably our another course - System Administration will create a slack group for our questions. 
 - In this assignment we are given a template file. It's really nice to have a template like that. But I have a request, can you please give the method any good name ? It's really tough to understand the function that, what are - bn(b) or nb(i, length), methods purpose. Then it would look great. I know that it's not industry level code but it's good to have nice method name in the code. Thanks. 

"""

def bn(b):
    # b - bytes to encode as integer
    # your implementation here
    byte_encoded_as_integer = 0
    for each_byte in b:
        byte_encoded_as_integer = (byte_encoded_as_integer << 8) | each_byte
    return byte_encoded_as_integer

def nb(i, length):
    # i - integer to encode as bytes
    # length - specifies in how many bytes the number should be encoded
    # your implementation here
    b = b''
    integer_to_encode_as_byte_list = []
    while length != 0:
        integer_to_encode_as_byte_list.insert(0, i & 255)
        i = i >> 8
        length = length - 1
    b = bytes(integer_to_encode_as_byte_list)
    return b

def encrypt(pfile, kfile, cfile):
    # your implementation here
    encoded_plain_text =  open(pfile, 'rb').read()
    decoded_plain_text = encoded_plain_text.decode()
    palin_text_byte_encoded_as_integer = bn(encoded_plain_text)
    encoded_key = os.urandom(len(decoded_plain_text))
    key_byte_encoded_as_integer = bn(encoded_key)
    cipher_text_as_integer = palin_text_byte_encoded_as_integer ^ key_byte_encoded_as_integer
    key_file = open(kfile, 'wb')
    ciphertext_file = open(cfile, 'wb')
    key_file.write(encoded_key)
    cipher_text_integer_to_encode_as_byte = nb(cipher_text_as_integer, len(decoded_plain_text))
    ciphertext_file.write(cipher_text_integer_to_encode_as_byte)


def decrypt(cfile, kfile, pfile):
    # your implementation here
    cipher_in_byte = open(cfile, 'rb').read()
    key_in_byte = open(kfile, 'rb').read()
    cipher_in_number  = bn(cipher_in_byte)
    key_in_number = bn(key_in_byte)
    original_text_in_number = cipher_in_number ^ key_in_number
    original_text_in_byte = nb(original_text_in_number,len(cipher_in_byte))
    original_text = original_text_in_byte.decode()
    orignal_text_file = open(pfile, 'w+')
    orignal_text_file.write(original_text)

def usage():
    print("Usage:")
    print("encrypt <plaintext file> <output key file> <ciphertext output file>")
    print("decrypt <ciphertext file> <key file> <plaintext output file>")
    sys.exit(1)

if len(sys.argv) != 5:
    usage()
elif sys.argv[1] == 'encrypt':
    encrypt(sys.argv[2], sys.argv[3], sys.argv[4])
elif sys.argv[1] == 'decrypt':
    decrypt(sys.argv[2], sys.argv[3], sys.argv[4])
else:
    usage()
