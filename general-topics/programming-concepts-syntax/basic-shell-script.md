
```php
#!/bin/bash
echo "Version: ${BASH_VERSION}"
echo "=============  1  ================="
echo "============= basic loop ================="

for i in 1 2 3 4 5
do
    echo "Welcome $i times "
done
echo "=============================="
echo "=============  2  ================="
echo "=============Loop range================="

X=5
for i in {1..5}
do 
    echo "Welcome $i times"
done
echo "==============================="
echo "============= 3  =================="
echo "=============Loop Interval================="
for i in {1..10..3}
do 
    echo "$i"
done
echo "=============  4  ================="
echo "=============Loop Basic C like================="

for((c=1;c<=$X;c++))
do 
    echo $c 
done

echo "========== POSITIVE OR NEGATIVE ========"
a=5
#if [ ] then else fi
if [ $a -lt 0 ]
then 
    echo "${a} is a negative number"
else
    echo "${a} is a positive number"
fi

```
#take input ->
#read variableName