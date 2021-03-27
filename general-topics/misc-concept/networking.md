### TCP
##### 3 way handshaking
i) client sends SYN to server(Seq: 9001,Ack: 0,Syn: 1)
ii) server sends back SYN/ACK to client(Seq: 5001,Ack: 9002,Syn: 1)
iii) client sends ACK(Seq: 9002,Ack: 5002,Syn: 0)

### TCP/IP Model
 TCP/IP model, also called the Internet Protocol Suite, with its four layers: application( Hypertext Transfer Protocol (HTTP) and the File Transfer Protocol (FTP).),transport, internet and link.
 
 Application layer protocol s use the transport layer to transfer messages between clients and servers. The transport layer provides end-to-end message transfer independent of the underlying network.It also splits the messages into segments and implements error control, port number addressing(application addressing) and additional features. The transport layer wraps layer-specific information around the segments and passes them to the internet layer.The internet layer, also called the IP layer, solves the problem of sending datagrams across one or more networks. To do so, the internet layer identifies and addresses the source host and the destination host and routes the datagrams hop by hop from the source to the intended destination. When the next hop is determined, the link layer implements the physical transmission of data to the next host. Upon reaching the final destination, the encapsulated datagram is passed upwards, layer by layer,until the entire message reaches the application layer for further processing
                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
 The application-layer protocol (HTTP) running between a client and a server, separated by two routers. On the client, the application-layer
message is passed down the network stack with each layer adding information
(headers and trailers) to the data it receives. At the link layer, the physical representation of each datagram (called a frame) is sent over wireless LAN (using the802.11x standard) to the first router and over Ethernet afterwards until the datagram reaches its destination, where the receiving host passes the data back up to the application layer. 
