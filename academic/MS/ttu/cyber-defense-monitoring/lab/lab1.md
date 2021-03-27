## Steps to follow
- initialize the VM
- reinitialize mac
- create new network adapter
- ifconfig to see the ip of the vm
- connet the vm via ssh
- go to /etc/rsyslog.d
- create a config file, my.conf
- put configuration `*.*	/var/log/test.log`
- restart `systemctl restart rsyslog`
- check the file if it contains all logs or not


```
tail -f /etc/httpd/conf.d/apache-syslog.conf
ps -ef | grep logger

logger -p mail.notice -t TEST "bla from forhad"
logger -p mail.alert -t TEST "bla from forhad"


```