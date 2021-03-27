#!/bin/bash
echo "[+] Generating RSA key pair..."
KEYSIZE=`shuf -n1 -e 2048 2041`
openssl genrsa -out priv.pem $KEYSIZE
openssl rsa -in priv.pem -pubout -out pub.pem

echo "[+] Testing encryption ($KEYSIZE-bit RSA)..."
echo "hello" > plain.txt
./rsa.py encrypt pub.pem plain.txt enc.txt
#ls -alh enc.txt
openssl rsautl -decrypt -inkey priv.pem -in enc.txt -out dec.txt
diff -u plain.txt dec.txt
#hexdump -C plain.txt
#hexdump -C dec.txt

# To see why openssl failed to decrypt the ciphertext do raw decryption with private key
# (the result should be correctly padded plaintext):
#openssl rsautl -inkey priv.pem -in enc.txt -decrypt -raw -hexdump
#exit

echo "[+] Testing decryption (PEM)..."
openssl rsautl -encrypt -pubin -inkey pub.pem -in plain.txt -out enc.txt
rm -f dec.txt
./rsa.py decrypt priv.pem enc.txt dec.txt
diff -u plain.txt dec.txt

echo "[+] Testing decryption (DER)..."
openssl rsa -in priv.pem -outform der -out priv.key
rm -f dec.txt
./rsa.py decrypt priv.key enc.txt dec.txt
diff -u plain.txt dec.txt

echo "[+] Testing signing..."
dd if=/dev/urandom of=filetosign bs=1M count=1 > /dev/null 2>&1
./rsa.py sign priv.pem filetosign signature
openssl dgst -sha256 -verify pub.pem -signature signature filetosign

# To see why openssl failed to verify the signature do raw decryption with public key
# (the result should be correctly padded DigestInfo DER):
#openssl rsautl -inkey priv.pem -in signature -encrypt -raw -hexdump
#exit

echo "[+] Testing successful verification..."
openssl dgst -sha256 -sign priv.pem -out signature filetosign
./rsa.py verify pub.pem signature filetosign

echo "[+] Testing failed verification..."
openssl dgst -md5 -sign priv.pem -out signature filetosign
./rsa.py verify pub.pem signature filetosign
