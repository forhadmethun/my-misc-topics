Facility codes:                                                                         Severity codes:

--- 
0 – kern (kernel messages)                                                              0 – emerg (system is unusable)
1 – user (user-level messages)                                                          1 – alert (immediate action needed)
2 – mail (mailing system)                                                               2 – crit (critical error message)
3 – daemon (system daemons)                                                             3 – err (error message)
4 – auth (authorization and security)                                                   4 – warning (warning message)
5 – syslog (internal messages of logging system)                                        5 – notice (normal but significant message)
6 – lpr (printing system)                                                               6 – info (normal informational message)
7 – news (network news system)                                                          7 – debug (debug message)
8 – uucp (UUCP system)
9 – cron (cron daemon)
10 – authpriv (authorization and security) Please note that severity codes define
11 – ftp (FTP daemon) a natural ordering for message severities -
12 – ntp (NTP system) a message with a smaller severity code
13 – (log audit) is regarded as more critical
14 – (log alert)
15 – cron (cron daemon)
16 – local0 (for local use)
17 – local1 (for local use)
...
23 – local7 (for local use


BSD syslog message
--- 

<PRI>Timestamp Hostname Message

``` 
<30>Dec 18 08:47:39 myhost sshd[15172]: log: Password authentication for alex accepted.
```


PRI = 8*Facility + Severity

● Facility – numerical code from 0 to 23 which denotes the message area or the sender type
● Severity – numerical code from 0 to 7 that denotes the message severity (0 is most critical and 7 is least critical)



IETF syslog message
--- 

<PRI> Version Timestamp Hostname Application PID MsgID StructData Message

```
<28>1 2012-11-17T12:33:59.223+02:00 myhost2 ids 1299 - [timeQuality tzKnown="1" isSynced="1"][origin ip="10.1.1.2"] port scan from 192.168.1.102
```





