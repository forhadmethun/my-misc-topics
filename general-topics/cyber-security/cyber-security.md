## What is cyber security
> securing ourselves from attacks carried out primarily from computer

> the more you secure the less target you are 

> mac, linux are secure? - nothing is 100% secure, 

## Cyber Security Terminology
- Terms
  - Attack
  - C I A model
    - confidentiallity
      - acess private, password protected data/info
    - integority
      - unauthority change. delete data
    - availability
      - data is aunavailable not not available  
  - Attack Code
    - related coding to hack
  - Integrity
  - Script Kiddies
    - hacker without significant programming knowlege
  - Exploit
    - method of attack is called exploit
  - Nation-States
  - Zero-Day Exploit
    - attackers know about vulnerability without knowing other
  - Hackers - who hacks
  - Hackivist
    - hacker + activist -> motivation is to spread awareness
  - Risk Assessment
  - Risk
    - vulnerabilities + threats + impact
  - vulnerability
    - may be personal fault, if we share all data publickly
    - potential weakness in a security system, loophole
  - Impact
    - consequence of an attack 
  - Threat
    - describe the likelihood of a given attack
    - someone has the potential to harm a system
  - Cyber Criminals
  - Confidentiality
  - Availability
  - Malicious Insider
    - apon manush k bishwash korle ja hoy r ki 

## Computers in's out's
 - 4 layers
   -  user 
   -  hardware
      -  HDD
      -  CD/DVD Drive
      -  CPU
      -  RAM
      -  I/O
      -  Network Connection Circuit
      -  Motherboard
   -  os
   -  application  
-  What happens when we turn on the computer?
   -  press power switch
   -  cpu gets power supply and run BIOS(basic input output software)(mounted in motherboard)()
   -  load boot Code(basically from hdd but possible to use another storage) loaded to RAM
   -  Run the Boot Code
   -  Load OS
   -  Run OS and startup apps
## How internet works?
 - internet 
   - network of network ( inter networking )
 - Who owns the networking devices that makes the internet possible
   - ISP 
     - private company
 - How computer communicate across the network?
   - set of communication rules 
     - protocols
     - Internet communication rules - internet protocol
 - every device has IP address 

## IP Address
  - DHCP ( Dynamic host configuration protocol )
    - assing ip dynamically
    - can be a physical server or can be inside router 
  - Private IP / Public IP
    - ISP provide a public ip address to a office but all the computer device inside the office may have use private IP 

## DNS
  - when we type name of website it goes to DNS server and it returns the ip address of the website
    - web page request -> ISP DNS -> First level DNS -> Root Level DNS(it contains multiple first level DNS, knows how to find IP address)

## How router direct info to the right IP address
  - Every computers & routers have Route table
  - when we reqeust for data in same network then route table redirect the data to that specific ip
  - when we request for data in different network then route table redirect to another router's route table and then another and finally we get the data

## Passwords and Hash function
  > password -> Hash Function -> Hashed Value
  - hash function are irreversible 
  - ex- 
    - which two prime numbers are multiplied to create number 3127
  - Common Password Threats
    - User Disclousure 
    - Social Engineering
      - Ami bkash theke mf boltes!! apnar halnagad choltase.. 
    - Phishing
    - Key Logger 
      - may be software or hardware
    - Wireless Sniffing
      - 
    - Brute Force Guessing
    - Dictionary Attacks
      - 
    - Password Files not encrypted
    - Exposed Password with known hash value 
    - Security Question




## Types of hackers
  - Black hat
    - without authority
  - White hat(ethical hacker)
    - authorized
  - Grey(black + white) hat
    - white hack with unauthorized activities


## Cyber Threats
  - Malware
  - Phishing
  - Password Attack
    - Bruit Force
    - Dictionary
    - Key Logger
  - DDos
    - high volume of request so that server flooded with request
  - Rough Software
    - malware with unnecessary security software
  - Malvertising
    - malicious code with advertise
  - Drive By Download
    - malware, download automatically
  - Man In the Middle
   - i communicate with bank but mim communicate with me and mim then communicate with bank 

## OSI Layers
 - A
 - P
 - S
 - T
 - N
   - controls subnetting, deliver packets from source to destination across multiple links
 - D
 - P

## XSS(cross site scripting) 
  - client slide code injection attack
  - happens when web applicaiton makes use of unvalidated or unencoded user input
  - xss attacks are used to redirect users to websites where attackers can steal data from them.

## Different threats
  - virus
    - malicious piece of software
  - worms
    - may replicate & copy to network without help of user
  - trozan horse
    - come packed inside another software with malicious code
## Ways to secure data
  - strong password
  - 2FA
  - 