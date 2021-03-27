#!/bin/bash

rm -f server.pem

echo "Testing eesti.ee:"
./tls_getcert.py https://www.eesti.ee/ --certificate server.pem	
read
openssl x509 -in server.pem -text | grep 'Subject:'
read

echo "Testing twitter.com:"
./tls_getcert.py https://twitter.com/
echo
read

echo "Testing live.com:"
./tls_getcert.py https://live.com/
echo
read


