## What is https?
    https = http + ssl(secure socket layer)
## Cryptography
    'Plain Text' ---> Encryption Algorithm( may use key string) --> 'Cipher Text'
    'Cipher Text' --> Decryption Algorithm( may use key string) --> 'Plain Text'
    > The key may be same for both encryption and decryption at that time it is called symmetric key encryption decryption. if different key used for the process then called asymmetric key encryption decryption.
    > Encryption key is public key, Decryption key is private key

    > only encrypted data from client side can be decrypted by server's private key. As man in middle never know the private key so the encrypted date cannot be decrypted. 
## How client(browser) Connects with server at the time of https? 
 1. client make a tcp connection on server's 443 port which is default for https 
 2. after connection establishment client sends a hello message which contains ssl version client supports, compression methods, cipher it can use and some random data for creating key. 
 3. server sends server hello message with ssl version which will be used, ciphers, compression method, session id and some random data for creating key. 
 4. after server hello msg, sever sends a digital certificate digitally signed by CA which servers two purpose (i) public key of server with which client will encrypt the data, chain of certificate ..  (ii) identity of server from which the webpage is coming
 5. server sends server hello done message
 6. client verify the certificate with CA authority as digital certificate created by CA's private key and client shipped with many public keys of CA & sends certificate verify message
 7. client sends change cipher spec by telling that from now all the communication will be encrypted
 8. client sends the finish message which contains the digest of all messages so far so that server can verify that no of the commands earlier were not tempered by other rather than client
 9. server sends change cipher spec msg like earlier by telling client that from now all communication will be encrypted 
 10.  server sends the finish message like earlier which contains digest of all message so far so that client can verify that no of the commands earlier were not tempered by other rather than server. 
 11.  client now generate a **symmetric secret key for this ssl session and by encrypting with the public key of server sends back to the server
 12.  when server gets the symmetric key it uses it's private key to decrypt it. Now the server gets the browsers shared key. From now all the traffic between client and server will be encrypted & decrypted with the same key.

> Asymmetric key algorithm(public key & private key) is used to verify the identity of the owner and its public key so that trust is built. Once the connection is established, symmetric key algorithm(shared key) is used to encrypt and decrypt all the traffic between them.

[ref1!](https://www.youtube.com/watch?v=JCvPnwpWVUQ)  
[ref2!](https://www.youtube.com/watch?v=33VYnE7Bzpk)