#!/bin/bash

# must be executed before:
#openssl genrsa -out priv_subject.pem 2041
#openssl req -new -key priv_subject.pem -out appcrypto.ee.csr

rm -f issued.pem

echo '$ ./issue_cert.py UT_priv.pem UT_rootCA.pem appcrypto.ee.csr issued.pem'
./issue_cert.py UT_priv.pem UT_rootCA.pem appcrypto.ee.csr issued.pem
echo
read

echo '$ openssl verify -CAfile UT_rootCA.pem -purpose sslserver issued.pem'
openssl verify -CAfile UT_rootCA.pem -purpose sslserver issued.pem
echo
read

echo '$ openssl verify -CAfile UT_rootCA.pem -purpose smimesign issued.pem'
openssl verify -CAfile UT_rootCA.pem -purpose smimesign issued.pem
echo
read

echo '$ openssl x509 -in issued.pem -text'
openssl x509 -in issued.pem -text
