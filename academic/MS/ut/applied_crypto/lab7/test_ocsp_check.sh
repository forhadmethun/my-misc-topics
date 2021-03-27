#!/bin/bash

echo '$ ./ocsp_check.py valid.pem'
./ocsp_check.py valid.pem
echo
read

echo '$ ./ocsp_check.py revoked.pem'
./ocsp_check.py revoked.pem
