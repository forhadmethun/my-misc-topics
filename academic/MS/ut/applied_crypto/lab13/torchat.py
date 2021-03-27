#!/usr/bin/env python3

# sudo apt install python3-socks
import argparse
import socks
import socket
import sys
import random
# do not use any other imports/libraries

# took 10.0 hours (please specify here how much time your solution required)


# parse arguments
parser = argparse.ArgumentParser(description='TorChat client')
parser.add_argument('--myself', required=True, type=str, help='My TorChat ID')
parser.add_argument('--peer', required=True, type=str, help='Peer\'s TorChat ID')
args = parser.parse_args()

# route outgoing connections through Tor
socks.setdefaultproxy(socks.PROXY_TYPE_SOCKS5, "127.0.0.1", 9050)
socket.socket = socks.socksocket

# reads and returns torchat command from the socket
def read_torchat_cmd(incoming_socket):
    # read until newline
    data = b''
    while True:
        r = incoming_socket.recv(1)
        if(r == b'\n'):
            break
        data +=r
    # return command
    cmd = data.decode("utf-8")
    return cmd

incoming_authenticated = False
status_received = False
cookie_peer = ""

# prints torchat command and sends it
def send_torchat_cmd(outgoing_socket, cmd):
    global status_received
    if (cmd[0] == 'status' and cmd[1] == 'available'):
        if(status_received == False):
            add_me = 'add_me'
            outgoing_socket.send(str.encode(add_me + "\n"))
            outgoing_socket.send(str.encode("status available" + "\n"))
            outgoing_socket.send(str.encode("profile_name forhad" + "\n"))
            status_received = True
    elif (cmd[0] == 'message'):
        message = input("[?] Enter message:")
        message = "message " + message
        print("[+] Sending:", message)
        outgoing_socket.send(str.encode(message + "\n"))

# def random_with_N_digits(n):
#     range_start = 10**(n-1)
#     range_end = (10**n)-1
#     return random.randint(range_start, range_end)


# server socket things
sserv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sserv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sserv.bind(( '127.0.0.1' , 8888))
sserv.listen(0)



# connecting to peer
myself = args.myself
peer = args.peer
print("[+] Connecting to peer ",peer)
myself_cookie = str(random.getrandbits(128))
ping = "ping " + myself + " " + myself_cookie
print("[+] Sending:",ping)
# sending ping
# client socket
HOST = peer + ".onion" #'127.0.0.1'  # The server's hostname or IP address
# HOST = myself + ".onion" #'127.0.0.1'  # The server's hostname or IP address
PORT = 11009 #65432        # The port used by the server
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))
client.send(str.encode(ping+"\n"))
# from_server = client.recv(4096)

# listening for the incoming connection
print("[+] Listening...")


# print("[+] Client %s:%s" % (address[0], address[1]))







(s, address) = sserv.accept()
print("[+] Client %s:%s" % (address[0], address[1]))
# main loop for processing the received commands
incoming_socket = s
peer_cookie = ''
while True:
    cmdr = read_torchat_cmd(incoming_socket)

    cmd = cmdr.split(' ')

    if cmd[0]=='ping':
        print("[+] Received: ping", cmd[1], cmd[2])
        peer_cookie = cmd[2]
    elif cmd[0] == 'pong':
        print("[+] Received:", cmd[0], cmd[1])
        if(cmd[1] == myself_cookie):
            print("[+] Incoming connection authenticated!")
            pong_message = "pong " + peer_cookie #cmd[1]
            print("[+] Sending:", pong_message)
            client.send(str.encode(pong_message + "\n"))
            incoming_authenticated = True
        else:
            sys.exit(1)
    elif cmd[0] == 'message':
        print("[+] Received:", cmdr)
    else:
        print("[+] Received:", cmd[0], cmd[1])
    if incoming_authenticated:
        send_torchat_cmd(client, cmd)

    # elif cmd[0] == 'version':
    #     print("[+] Received:", cmd[0], cmd[1])
    # elif cmd[0] == 'profile_name':
    #     print("[+] Received:", cmd[0], cmd[1])
    # elif cmd[0] == 'status':
    #     print("[+] Received:", cmd[0], cmd[1])

"""
torchat.py --myself 7jghot5mfw6gyg5q36kvsvkbzs6isrzbjhbnrqcdvmyrfim2y3vuadad --peer 73knywjeeq6tjuorqzhtn33rs4a
[+]

Connecting to peer 73knywjeeq6tjuorqzhtn33rs4azfucwbzrkcj67dojrm57jgxhfjnyd
Sending: ping 7jghot5mfw6gyg5q36kvsvkbzs6isrzbjhbnrqcdvmyrfim2y3vuadad 36251593687951013345829332738750401089
Listening...
Client 127.0.0.1:49900
Received: ping 73knywjeeq6tjuorqzhtn33rs4azfucwbzrkcj67dojrm57jgxhfjnyd 114550899558407750467319526697617679065
Received: pong 36251593687951013345829332738750401089
Incoming connection authenticated!
Sending: pong 114550899558407750467319526697617679065735261062805617012379414337324471905588
Received: client TorChat
Received: version 0.9.9.553
Received: profile_name Bob
Received: status available
Sending: add_me
Sending: status available
Sending: profile_name Alice
Received: status available
Received: message Who are you, Alice?
Enter message: I am your friend.
Sending: message I am your friend.
Received: status available
Received: status available
Received: status available
"""