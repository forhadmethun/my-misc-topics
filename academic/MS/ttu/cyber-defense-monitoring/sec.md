# Single
```
# This rule writes info about every dropped packet immediately to standard output:
type=Single
ptype=RegExp
pattern=kernel: iptables: .* SRC=([\d.]+) .* PROTO=(\w+) .* DPT=(\d*)    
desc=Dropped packet from source $1 protoco $2 destport $3
action=wite - %s

```
# Supress 
``` 
# prevent matching for going further

type=Suppress
ptype=SubStr
pattern=192.168.0.112
```

# Single With Script

``` 
# uses external program for matching

type=SingleWithScript
ptype=RegExp
pattern=kernel: iptables:.* SRC=([\d.]+).* PROTO=(\w+) .* DPT=(\d*)
script=ping -q -c 3 $1
desc=Dropped packet frm pingable source $1 protocol $2 destport $3
action=write - %s

```

# Single With Suppress 
``` 
# handle repeated messages, suppreses! for a certain TIME, 
# waring mail sent to local root-user for first event then silently consumes events next 10 minutes

type=SingleWithSuppress
ptype=RegExp
pattern=sshd\[\d+]\]: Failed password for (\S+) from ([\d.]+) port \d+ ssh2
desc=SSH login failed for user $1 from $2
action=pipe '%s' mail root@localhost
window=600
```

# Pair 
``` 
# for matching event A, executes an action list then waits(ignores same events) until event B comes and on arrival of event B, excutes another action list
# jody B na ashe taile certain time por kichu ekta korte hobe!

# 5 minit er majhe vul login er por thik login na hole 1 hour er jonno context create kore rakhbe, tarpor context er according er action list execute korbe

# jody 5 mint er majhe vul login er por thik login ashe taile, context ta delete kore dibe, action tao execute korbe

type=Pair
ptype=RegExp
pattern=sshd\[\d+\]: Failed password for (\S+) from ([\d.]+) port \d+ ssh2
context=!LOGACTIVE_$2
desc=Failed login for user $1 from $2
action=shellcmd /sbin/iptables -I INPUT -s $2 -j LOG; \
    create LOGACTIVE_$2 3600(shellcmd /sbin/iptabless -D INPUT -s $2 -j LOG)
pattern2=sshd\[\d+\]: Accepted password for $1 from $2 port \d+ ssh2
desc2=Successful login for user %1 from %2
action2=shellcmd /sbin/iptabless -D INPUT -s $2 -j LOG;\
    delete LOGACTIVE_%2
window=300

```

# Pair With Window
``` 
# A match korar porei, kono action list execute hobe na, firstly wait korbe t second porjonto action B er jonno, jody B k pay taile ekta action list execute korbe noile arekta list execute korbe

type=PairWithWindow
ptype=RegExp
pattern=kernel: iptables:.* SRC=([\d.]+) .* PROTO=TCP .* DPT=23\b
action=pipe '%s' mail root@localhost
desc=Blocked TELNET access from IP $1
ptype2=RegExp
pattern2=sshd\[\d+\]: Accepted (.+) for (\S+) from $1 port \d+ ssh2
desc2=TELNET access from IP %1 followed by $1 login for user $2
action2=pipe '%s' logger -p autopriv.info -t sec
window=20


```

# Single With Threshold
``` 
# gunte thake same input list, jody t second e thereshold exceed kore taile action list execute kore
type=SingleWithThreshold
ptype=RegExp
pattern=sshd\[\d+\]: Faild .+ for invalid user (\S+) from ([\d.]+) port \d+ ssh2
desc=Repeated ssh probing of user $1 from $2
action= pipe '%s' mail -s 'probing from $2' root@localhost; \
    pipe '%s' logger -p autopriv.info -t sec
thresh=3
window=300

```

# Single With2 Thresholds
```
# 2nd round e counting kore!! firstbar sesh kore arekbar mone hoy..

type=SingleWith2Thresholds
ptype=RegExp
pattern=sshd\[\d+\]: Failed .+ for invalid user \S+ from ([\d.]+) port \d+ sh2
desc= Repeated ssh probing of non-existing users from $1
action=shellcmd /sbin/iptables -I INPUT -p tcp -s $1 --dport 22 -j DROP
thresh=5
window=300
desc2=Allow ssh access again for $1
action2=shellcmd /sbin/iptables -D INPUT -p tcp -s $1 --dport 22 - jDROP
thresh2=0
window2=3600
```
# event group
# calendar rule