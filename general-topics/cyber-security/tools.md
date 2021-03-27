### Nmap(Network Mapper)
---
provides number of features for network discovery, security auditing, probing computer network, including host discovery and service and operating system detection. 
##### Features
Nmap uses raw IP packets in novel ways to determine:
- Host discovery
- what services (app name,version) hosts are offering
- Port Scanning
- Version Detection
- OS detection(version)
- Scripting
##### Usage
- auditing security
- identifying open ports
- network mapping, inventory
- generating traffic to hosts on a network, response analysis and response time management
- find and exploiting vulnerabilities in a network
- dns queries and sub-domain search
##### Description
- Among the output key is the 'interesting ports table'
- the table lists the port number and protocol, service name & state
- state is
    - open
    - filtered ( firewall, filter or other network obstacle is blocking)
    - closed
    - unfiltered ( responsible eto nmap probes)
##### Synopsis
```
    nmap [<scan type>..] [<option>] {<target specification>}
```
##### Example query
```
    nmap -A -T4 IP_ADDRESS
# -A is for enabling OS and version detection, script scanning & traceout
# -T4 for faster execution
```


### OpenVAS
--- 
full featured vulnerability scanner. capable of: unauthenticated testing, authenticated testing, different highlevel and lowlevel internet & industrial protocol


### tcpdump
--- 
a utility to capture and analyze packets on network interfaces. details can be displayed on the console or can be saved to a file for later analysis. it uses libpcap library for packet capturing.
```
tcpdump -h #shows version number
sudo tcpdump -D #shows all interface
sudo tcpdump -i any #shows all packets from all interfaces
sudo tcpdump -i any -c 5 #shows specific numbers of packets from all interfaces
sudo tcpdump -i any -c 5 -n #shows specific numbers of packets from all interfaces with ip address
sudo tcpdump -i any -c 5 -n -s96 #shows specific numbers of packets from all interfaces with ip address of specific byte size, maxzie: 65,535
sudo tcpdump -i any -w capture.pcap #saves capture to a file
sudo tcpdump -i any -w capture.pcap -v #saves capture to a file, verbose
sudo tcpdump -i any -w capture.pcap -v -c20 #saves capture to a file, verbose, limiting to 20 packates
sudo tcpdump -n -r capture.pcap | less #reading
sudo tcpdump -i eth1 -n host 10.0.0.0 -c5 # filtering where host 10.0.0.0 
sudo tcpdump -i eth1 -n src host 10.0.0.0 -c5 # filtering where host 10.0.0.0 
sudo tcpdump -i eth1 -n src host 10.0.0.0 and host 10.0.0.1 and port 80 -c5 # filtering where host 10.0.0.0 , compound expressions are supported
# can be filtered based on mac address
command -XX # more info
command -A # more info
command -vvv # more info
command -q # 
command -t # 
command -ttt # 
command -ttttt # 

```