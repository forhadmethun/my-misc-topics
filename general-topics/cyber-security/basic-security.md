### What kinds of things may be security issue?
 - simple file transfer protocol(FTP), file may contain authentication data
 - not using encrypted data
 - sql injection

### What is FTP? What is Telnet?
 - FTP: File Transfer Protocol
 - Telnet: Used to access another pc via terminal, now we use ssh.
### What is at risk if we don't use https?
 - we transfer sessionid via http header, cookie
 - http doesn't have encryption, 
 - anybody can steal data via http
### Should we use root as user in server?
 - it's bad idea cause anybody can manipulate any date in the server system.
 - we may create user in the server pc.
### How may we give permission to a group?
 - with the linux command g+r(group can read), instead of a+r(all can read).
 - if proper permission not given then anybody can sneak about the files.
 - There are software like suPHP which specify which user can modify the file only.

### Command to show all process?
`ps aux | grep httpd` 
(aux -> all)  
(grep -> find)  
(httpd -> a command)  

### Session Hijacking
 - physical access to any computer then it's possible
 - Packet Sniffing
 - Session Fixation / Spoofing
 - XSS - Cross Site Scripting 

 - potential solution is to use encryption 

### What is needed to use SSL?
 - need to buy certificate
 
 - private key, public key  

### Publick-Key Cryptography
 - two big random numbers are generated which are related mathematically. 
 - only the private key can decrypt the data which are encrypted by the public key.
 - ex:
   - I want to buy something from amazon. amazon has a public and a private key. I also have a public and private key. When I want to send some request to amazon then I use the public key to encrypt the data and send it to the amazon. Amazon then uses it's private key to decrypt the data. Likely, when amazon want to send me some data, then amazon will encrypt the data with my public key, then only I can decrypt the data.

### How cookie may help intruder?
 - it may share confidential data.