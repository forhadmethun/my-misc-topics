# IPtables
## Basic Concepts
 - Tables
   - filter
     - packet filtering
   - nat
     - network address translation
   - mangle
     - change ip header
   - raw
     - connection tracking
   - security
     - tagging
 - Chains
   - pre-routing
   - input
   - forward
   - output
   - post-routing
 - Rules
   - matching component + target componenet
     - terminating target
     - non terminating target

## Command Syntax
 `iptables -t[table] -OPTIONS[CHAIN] [matching component] [action component]`
 - if -t unavailable then default table is filter
 - OPTIONS[CHAINS]
   - depends on table, different table has different chain
   - options give the opportunity to control/modify/change the chain
   - available option:
     - A    : Append
     - D    : Delete
     - I    : Insert
     - R    : Replace
     - Z    : Zero Counters
     - L    : List
     - P    : Policy
     - E    : Rename
     - F    : Flush
     - N    : New User Defined
     - X    : Delete

 - [matching component]
   - if condition true ? Do this : continue traverse
   - many options for that one 
     - Generic
       - p : protocol
       - s : source ip
       - d : dest ip
       - i : input interface
       - o : output interface
     - Implicit [based on protocol]
       - tcp
         - sport
         - dport
         - tcp-flags
     - Explicit
       - m : match extensions
 - [action component]
   - j
     - ACCEPT
     - DROP
     - REJECT
     - RETURN

```
# L: list, n: numeric, v: verbose
iptables -L -n -v 
# a table can be specified
iptables -t mangle -L -n -v

#accept all traffic, so that won't be locked out of the server
iptables -P INPUT ACCEPT
#flush changes
iptables -F
#accept all packet coming to localhost interface
iptables -A INPUT -i lo -j ACCEPT
#accept all the packets which state is in ESTABLISHED, RELATED. The -m flag load module
iptables -A INPUT -m state --state ESTABLISHED, RELATED -j ACCEPT
#accept all the packets coming through ssh
iptables -A INPUT -p tcp --dport 22 -j ACCEPT
# drop all the other packets coming to the system
iptables -P INPUT DROP
# drop all the packets the want to be routed thorugh the system
iptables -P FORWARD DROP
# accept all the packet to outgo from the server system
iptables -P OUTPUT ACCEPT
# show list of the iptable rules
iptables -L -v
```


```
# drop all traffic of google.com
iptables -A INPUT -s google.com -j DROP
# delete the rule
iptables -D INPUT 1

#drop all the packet
iptables -P INPUT DROP  
#accept all the packet
iptables -P INPUT ACCEPT  
```
# Nftables
```
#install in debian
apt install nftables

# list current config
nft list ruleset

#flush existing ruleset
nft flush ruleset

# adding a table
nft add table inet MyTable

# adding a chain in the table
# the table is for packet filtering
# hook input
# chain with smaller priority appied first
nft add chain inet MyTable MyInput '{type filter hook input priority 0; policy accept;}'

# adding empty chain
nft add chain inet MyTable MyChain

# accept traffic of established connections and related packet
nft add rule inet MyTable MyInput ct state established, related counter accept

#
nft add rule inet MyTable MyInput tcp dport 22 ct state new counter accept

#
nft add rule inet MyTable MyInput meta iifname "lo" counter accept

#log info and drop else
nft add rule inet MyTable MyInput log prefix \"nftables: \" counter drop
```

```
flush ruleset
table inet MyTable {
 chain MyInput {
 type filter hook input priority 0; policy accept;
 ct state established,related counter accept
 meta iifname "lo" counter accept
 ip saddr { 10.1.1.0/24, 10.1.2.17 } tcp dport { 22, 80 } ct state new counter accept
 counter reject
 }
}
```
```

```


