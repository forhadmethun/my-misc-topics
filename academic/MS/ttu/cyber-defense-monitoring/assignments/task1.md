## Task Description
- The sequence consists of one or more parts. If there are two or more parts, they are separated with a comma (",") character.

- Each part of the sequence is a software module name which is optionally followed by a version number. If the version number is present, there must be a dash ("-") character between the software module name and the version number. If there is no version number, the use of dash character after the software module name is not permitted.


- Software module name must contain at least one character and must begin with a letter, and may contain letters and digits only.


- The version number consists of one or more elements. If there are two or more version number elements, these elements must be separated with a dot (".") character. Note that the dot character may not appear before the first or after the last element. Each version number element must be a sequence of one or more digits which may be optionally followed by one letter.


## Examples of sequences the regular expression must match:
```
m4-1.4.16
(the sequence has one valid part -- a software module name with a version number of three elements) 
coreutils,pcre-8.32
(the sequence has two valid parts -- note that the first part does not have a version number) 
libtasn1-4.09a,GeoIP-1.5.0,iwl6000g2a
(the sequence has three valid parts, with the first and second parts having version numbers) 
iwl2030,a12bcd3456ef78gh,mydatabase-13i.222.5b,e2fsprogs,PyYAML
(the sequence has five valid parts, where only the third part has a version number) 
```

## Examples of sequences the regular expression must NOT match:
```
coreutils, pcre-8.32
(the second part begins with a space character which is illegal) 
coreutils 8.22,pcre--8.32
(the first part contains a space character which is illegal; also, in the second part the software module name 
and version number are separated by two dash characters which is illegal) 
m4-1.4.16,
(the first part ends with comma, but there is no following second part) 
my_db
(the software module name contains an illegal character _) 
mydb-11A3.1
(the first version number element contains a character A, but A is not the last character of the version number element) 
mydb-11..2
(version number contains two dots, but there is no version number element between them) 
mydb-
(software module name is followed by -, but there is no version number) 
mydb-12ab.1
(the first version number element ends with more than one letter which is illegal)
mydb,,mydaemon
(the second part of the sequence is empty) 
!"libtasn1-4.09a,GeoIP-1.5.0,iwl6000g2a
(the sequence begins with illegal characters) 
coreutils-8.22,pcre-8.32+%
(the sequence ends with illegal characters)
```

## Solution
### The naming
^[[:alpha:]][[:alnum:]]*$  
### The version number
^(([0-9]+[[:alpha:]]?)(\.[0-9]+[[:alpha:]]?)*)$
### The seperator
(-(,?)+)?
### Altogether
```
[[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?
#(,([[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?)*)

[[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?(,([[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?)*)
```



^[[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?(,([[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?))*$


## Final Solution
```
egrep "^[[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?(,([[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?))*$"

```
^[[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?(,([[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?))*$
egrep "^[[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?(,([[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?))*$"
egrep "^[[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?(,([[:alpha:]][[:alnum:]]*(-(([0-9]+)[[:alpha:]]?(\.[0-9]+[[:alpha:]]?)*))?))*$"

iwl2030,a12bcd3456ef78gh,mydatabase-13i.222.5b,e2fsprogs,PyYAML





# Practice from test
``` 

egrep "^firewall\[[0-9]+\]: (([[:alnum:]]*[[:alpha:]]+)|([[:alpha:]]+[[:alnum:]]*))=[[:alnum:]]+(,(([[:alnum:]]*[[:alpha:]]+)|([[:alpha:]]+[[:alnum:]]*))=[[:alnum:]]+)*$"

```