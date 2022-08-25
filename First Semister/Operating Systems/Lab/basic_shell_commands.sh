#!bin/bash

echo "Basic stuff"

cat /etc/shells
a=10
vehicle="Something"

echo "The name of my vehicle is: $vehicle, it has $a tires"

echo "Enter some number:"
read value
if [ $value -gt 0 ]
then
echo "It is a positive value"
elif [ $value -lt 0 ]
then
echo "It is a negative value"
else
echo "It is 0 probably"
fi

# Loops

for i in 1 2 3 4 5
do 
echo "Welcome $i times"
done

# While loop

i=1; n=1

while [ $i -le 10 ]
do
    echo "$n * $i =" `expr $i \* $n`
    i=`expr $i + 1`
done

# case statements

read var

case $var in
1) echo "one";;
2) echo "Two";;
3) echo "Three";;
4) echo "Four";;
*) echo "BRUHH";;

esac