#!/bin/bash

rm -f auth.pem
rm -f sign.pem

echo "$ ./esteid_info.py"
./esteid_info.py
echo
read

echo "$ ./esteid_getcert.py --cert auth --out auth.pem"
./esteid_getcert.py --cert auth --out auth.pem
echo
read

echo "$ openssl x509 -in auth.pem -text | grep 'X509v3 Key Usage' -A 1"
openssl x509 -in auth.pem -text | grep 'X509v3 Key Usage' -A 1
echo
read

echo "$ ./esteid_getcert.py --cert sign --out sign.pem"
./esteid_getcert.py --cert sign --out sign.pem
echo
read

echo "$ openssl x509 -in sign.pem -text | grep 'X509v3 Key Usage' -A 1"
openssl x509 -in sign.pem -text | grep 'X509v3 Key Usage' -A 1
echo
read

# wget https://sk.ee/upload/files/ESTEID-SK_2015.pem.crt
# wget https://c.sk.ee/esteid2018.pem.crt

echo "$ openssl verify -partial_chain -CAfile ESTEID-SK_2015.pem.crt auth.pem"
openssl verify -partial_chain -CAfile ESTEID-SK_2015.pem.crt auth.pem
echo
read

echo "$ openssl verify -partial_chain -CAfile esteid2018.pem.crt sign.pem"
openssl verify -partial_chain -CAfile esteid2018.pem.crt sign.pem
echo
read
