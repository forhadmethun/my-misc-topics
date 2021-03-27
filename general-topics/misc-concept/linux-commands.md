Some  Commands

- if drive cannot be accessed:
  
        sudo ntfsfix /dev/sdXY

- if windows drive is not accessible from 

        sudo mount -t ntfs-3g -o remove_hiberfile /dev/sda3 /mnt/spider


- command to unzip tar.gz..

        tar -zxvf file.tar.gz


- new Tab in  Terminal:
        
        ctrl + shift + T

- Find a file IN 
        
        locate fileName

- Find a Directory in 
        
        find . -type d | grep DIRNAME

- New Tab in File Explorer: 
        
        ctrl + T 

- Minimize Current Window:
        
        In a default installation the keys are the following:

- Maximize: Ctrl+Super+↑
- Restore: Ctrl+Super+↓
- Minimize: Ctrl+Alt+0 (the keypad 0)

- rearrange windows :
  
        Ctrl + Alt + 1
        Ctrl + Alt + 2
        Ctrl + Alt + 3
        Ctrl + Alt + 4
        Ctrl + Alt + 6
        Ctrl + Alt + 7
        Ctrl + Alt + 8
        Ctrl + Alt + 9
        Ctrl + Alt + 0

- Some Maven Commands:
        
        mvn clean install && sudo cp target/oisf-1.2.war /var/lib/tomcat8/webapps/ROOT.war && sudo service tomcat8 force-reload && tail -f /var/log/tomcat8/catalina.out

        mvn install:install-file -Dfile=jdom.jar -DgroupId=revesystems -DartifactId=jdom -Dversion=1.0 -Dpackaging=jar -DgeneratePom=true

        mvn install:install-file -Dfile=mysql-connector-java-3.0.14-production-bin.jar -DgroupId=revesystems -DartifactId=mysql-connector -Dversion=1.0 -Dpackaging=jar -DgeneratePom=true

- copy files via terminal:
        
        sudo cp target/oisf-1.2.war /var/lib/tomcat8/webapps/ROOT.war

- App Finder for : 
        
         Easy App Find
        download Gnome DO or Albert *
- Unlock pdf:

        gs -sPDFPassword=$PASS -q -dNOPAUSE -dBATCH -sDEVICE=pdfwrite -sOutputFile=%stdout% -c .setpdfwrite -f locked.pdf > unlocked.pdf
        (gs = > ghostscript) 

- kill  process:
        
    - To list any process listening to the port 8080:

            lsof -i:8080
    - To kill any process listening to the port 8080:

            kill $(lsof -t -i:8080)
    - or more violently:

            kill -9 $(lsof -t -i:8080)
    - another- way to kill process - 
            
            This fuser 8080/tcp will print you PID of process bound on that port.

            And this fuser -k 8080/tcp will kill that process.

            Works on  only. More universal is use of lsof -i4 (or 6 for IPv6).


- Process List:

        ~/top
        ~/ps

- more:
        
        With locate *.png | more we will get the results page by page, and we can reveal the next pages by pressing space. We quit by pressing "q".
- less: 
        
        With locate *.png | less we will still get the first page of results, but navigate up and down with the arrow keys. Again, we quit with "q".
- touch:
        
        touch command - a.k.a. the make file command - allows users to make files using the  CLI. Just as the mkdir command makes directories, the touch command makes files. Just as you would make a .doc or a .txt using a PC desktop, the touch command makes empty files. An example of the touch command:
- grep:
        
        grep -r "line" *
        grep "lines.*empty" demo_file
- locate:
        
        locate .*png
- google-chrome:
        
        google-chrome www.youtube.com
- history:
        
        history | more

- Clear Terminal Shortcut: 
    
        Ctrl + L

- Next Window:
        
        Ctrl + Alt + up/down/right/left

- Move To Next Window:
        
        Ctrl + Shift + Alt + up/down/right/left
- About user
        
        :~/ who
        :~/ whatis command_name

- command for details view : 
        
        ll -lh

- just open mysql in lampp
        
        sudo /opt/lampp/lampp startmysql

- vim commands:

        i -> insert 
        ZZ -> save and exit
        :wq -> save and exit
        q -> quit without saving 
        :q! -> discard all changes 
- text document file contents

        cat fileName -> show file contents
        tac fileName
        uniq fileName
        less fileName -> show file contents ( big file ) 

        head -n fileName -> shows first n line of file
        tail -n fileName ->shows last n line of file 
        sort [-option][path] 
        nl fileName -> show file with line number
        nl -s '. ' -w 10 fileName
        wc fileName -> word count of the file
        wc -lw fileName -> -l(line#) , -w(word#)

- wildcard:

        ls d*
        ls *.sh
        ls ?*
        ls [sv]*
        ls *[0-9]*
        ls [^e-g]*
- file format
    
        file fileName/directoryName -> shows details about file format 
- directory contents 
        
        ls -a -> -a shows all hidden files 

- permission

        _rwxrwxrwx 
        drwxrwxrwx
        (type)(owner)(group)(user)

        chmod [permission] [path]
        [ugoa]
        >user, group , other, all 
        >+,- ( granting or revoking permission)
        >rwx(read, write, execute] 


        ls -l
        ls -ld    #shows permission for a directory 

        chmod g+x fileName    #grant execute to group 
        chmod u-w fileName    #rovoke writing to user
        chmod g+wx fileName    #grant write and execute to group
        chmod go-x fileName    #revoke execute to user and group

        chmod 400 fileName #provide only read to user and no permission for other 


- Grep & Reg-ex

        grep 'stringToSearch' fileName
        grep -n 'stringToSearch' fileName    #if want to see line Number
        grep 'regularExpression' fileName

- piping and redirection:

        > save output to a file
        >> append output to a file
        <read input from a file 

- setting directory as a variable for further use in terminal:

        myvar="$PWD"
        cd "$myvar"
        or
        myvar=`pwd`
        # ...
        cd $myvar

- browser full -screen : 
        
        chromium-browser --app=http://example.com --start-fullscreen

- pc ip info

        hostname -i
        hostname -I ( ip address of pc) 
- terminal close
    
        Ctrl + C (stop) 
        Ctrl + Z ( force stop ) 

- Command	Description	Example

        >	Redirect output to filename	$ echo foo > foo.txt
        >>	Append output to filename	$ echo bar >> foo.txt
        cat <file>	Print contents of file to screen	$ cat hello.txt
        diff <f1> <f2>	Diff files 1 & 2	$ diff foo.txt bar.txt
        ls	List directory or file	$ ls hello.txt
        ls -l	List long form	$ ls -l hello.txt
        ls -rtl	Long by reverse modification time	$ ls -rtl
        ls -a	List all (including hidden)	$ ls -a
        touch <file>	Create an empty file	$ touch foo
        mv <old> <new>	Rename (move) from old to new	$ mv foo bar
        cp <old> <new>	Copy old to new	$ cp foo bar
        rm <file>	Remove (delete) file	$ rm foo
        rm -f <file>	Force-remove file	$ rm -f bar

- Command	Description	Example

        curl	Interact with URLs	$ curl -O example.com
        which	Locate a program on the path	$ which curl
        head <file>	Display first part of file	$ head foo
        tail <file>	Display last part of file	$ tail bar
        wc <file>	Count lines, words, bytes	$ wc foo
        cmd1 | cmd2	Pipe cmd1 to cmd2	$ head foo | wc
        ping <url>	Ping a server URL	$ ping google.com
        less <file>	View file contents interactively	$ less foo
        grep <string> <file>	Find string in file	$ grep foo bar.txt
        grep -i <string> <file>	Find case-insensitively	$ grep -i foo bar.txt
        ps	Show processes	$ ps aux
        top	Show processes (sorted)	$ top
        kill -<level> <pid>	Kill a process	$ kill -15 24601
        pkill -<level> -f <name>	Kill matching processes	$ pkill -15 -f spring


- Command	Description	Example

        mkdir <name>	Make directory with name	$ mkdir foo
        pwd	Print working directory	$ pwd
        cd <dir>	Change to <dir>	$ cd foo/
        cd ~/<dir>	cd relative to home	$ cd ~/foo/
        cd	Change to home directory	$ cd
        cd -	Change to previous directory	$ cd && pwd && cd -
        .	The current directory	$ cp ~/foo.txt .
        ..	One directory up	$ cd ..
        find	Find files & directories	$ find . -name foo*.*
        cp -r <old> <new>	Copy recursively	$ cp -r ~/foo .
        rmdir <dir>	Remove (empty) dir	$ rmdir foo/
        rm -rf <dir>	Remove dir & contents	$ rm -rf foo/
        grep -ri <string> <dir>	Grep recursively (case-insensitive)	$ grep -ri foo bar/

## Some linux commands
 - update
   - update the list file
 - upgrade
   - pull the change from the list
```
  199  find / -name 'mysql'
  202  find / -name 'php'
  203  find / -name 'apache'
  207  touch test.txt
  209  find -cmin -20
  210  find / -name 'php.ini'

```
 - add user

```
sudo adduser tim
vim /etc/passwd
passwd
sudo passwd tim
sudo chfn #change profile
sudo usermod tim #give options what can we do with usermod,ex: you can lock user
sudo deluser tim #delete user
sudo rm -rf /home/time
```
 - vim 
   - next : / then enter then n
   - prev: shift n
   - if change something but want to quit: :q!
   - if just see and no modification then need to quit: :q

### Group management
```
vim /etc/group #to see different groups 
sudo addgroup testgroup
sudo adduser ralph testgroup
sudo deluser bob testgroup
```

## Rename, move, copy, del
```
cp
mv
rm
mkdir
mv
cp 
rm
```
## Start stop restart Servers
 - systemd, systemctl, service, init.d
```
 sudo systemctl status #shows status of all servers 
 sudo systemctl status apache2
 sudo systemctl stop apache2
 sudo systemctl start apache2
 sudo systemctl restart apache2


 sudo service --status-all | less
 sudo service apache2 status
 sudo service apache2 stop
 sudo service apache2 status
 sudo service apache2 start
 sudo service apache2 restart


 #deprecated
 sudo /etc/init.d/apache2 status
 sudo /etc/init.d/apache2 stop

```
## Task manager
```
top #press h to get all options
# to search, perss o then - COMMAND=apache2
```

## Permission
 - user, group, other
 - rwx
   - add to get all the permission
   - 421
   - 6 = 4 + 2 = rw
   - 7 = 4 + 2 + 1 = rwx

```
groups
groups tim
sudo apt-get install members
members testgroup
members anothergroup
cat /etc/group | less
sudo chown tim:testgroup filename #change the file to certain owner/group
sudo chown tim filename
sudo chown :testgroup filename
sudo chown -R bob:testgroup testFolder #recursively do all 
sudo chmod 777 testFile
sudo chmod -R 777 testFolder
```

## Tar, Archive, Compress
```
tar -czvf x.tar.gz testFolder
#create zip verbose foldername
tar --list -f x.tar.gz #show all files of the tar
cp x.tar.gz newFolder/y.tar.gz
cd newFolder
tar -xzvf y.tar.gz
# extract unzip 
```

## Cron Tab
```
crontab -e
#goto: crontab.guru
crontab -l
sudo crontab -u tim -l
```
## SSH
```
sudo systemctl status sshd
sudo apt-get instal openssh-server
ssh bob@10.0.1.4 
```
## ftp server
```
sudo apt-get install vsftpd
# create new user for ftp for sharing file
sudo /etc/passwd
sudo vim /etc/vsftpd.conf #Edit vsftpd.conf file to allow write privileges over FTP.
#Remove # from infant of write_enable=YES
sudo systemctl restart vsftpd # Restart vsftpd to make configuration changes active
#Home Directories for Users are configured in /etc/passwd file. This can be modified.

```

## Firewall
```
ufw enable
sudo ufw status verbose
sudo ufw allow 21
sudo ufw allow from 10.0.1.19 any port 22
sudo ufw allow from 10.0.1.0/24 any port #from any specific subnet
sudo ufw allow fpt
sudo ufw status numbered
sudo ufw delete [number]
sudo ufw reset
sudo ufw eable
sudo ufw status verbose
```

## Network config
```
ifconfig
ip addr
route -n
sysetmd-resolve --status
sudo dhclient -v -r
sudo dhclient -v
```

```
# Set Static IP Address

Navigate to: /etc/netplan/
sudo vim file.yaml – edit thye file that ends in yaml
network:
  version: 2
  renderer: networkd
  ethernets:
    ens3:
      dhcp4: no
          addresses:
              - 192.168.121.199/24
          gateway4: 192.168.121.1
          nameservers:
              addresses: [8.8.8.8, 1.1.1.1]
sudo netplan apply – apply network changes

```
## DNS
- 4 types
 - DNS Resolver
   - local ISP
 - Root Name Server
     - operated by 12 org, holds ip where .com reside
 - Top Level Domain(TLD)
   - knows ip for all domain shared common extension like .com
 - Authoritative Name Server 
   - knows the actual ip of requested website   
```
nslookup
set query=ns
facebook.com

```