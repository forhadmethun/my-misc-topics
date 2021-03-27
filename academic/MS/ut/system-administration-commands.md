# DNS Setup
  - [ref](https://courses.cs.ut.ee/2020/sa/spring/Main/DNS)
 1. Secure ssh server
 2. update packages using package manager
    *  uninstall packages
        ```
        # Uninstall the not used packages
        yum autoremove -y
        yum clean all
        ```
 3. Perform backups
 4. Open port 53
 5. Disable IPV6
 6. DNS using BIND Software
    * Domain Hierarchy
    * Changing hostname
        ```
        $ hostname
        # the upper command is basically is the concent of the file: /etc/hostname, so to change the hostname need to edit that file

        # /etc/hosts , provides hostname -> ip, dns resolved from this file
        ```
7. Config. BIND Name Server



# Apache Server Setup
```
setsebool -P httpd_can_network_connect=1
systemctl restart named
systemctl restart httpd


systemctl enable firewalld
systemctl start firewalld
systemctl status firewalld
```
# change owner of a file
```
chown username filename
```

# create an user
``
eradd username
```


# start in next run
```
systemctl enable httpd
```
# to check if it will run in next startup or not
```
systemctl is-enabled proxy
```

```
# forhad00 in mysqldb in b98388
```

# See if something is listening on port
```
sudo netstat -plnt | grep ':80'
```