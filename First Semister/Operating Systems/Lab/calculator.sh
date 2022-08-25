#!bin/bash

echo "Welcome to Super Bashing Calculator"

what_to_do=0

while [ $what_to_do -ne 5 ]
do

echo "Enter the first number"
read var1
echo "Enter the second number"
read var2
echo "What would you like to do with these 2 numbers"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Quit"
read what_to_do
case $what_to_do in

1) echo "$var1 + $var2 =" `expr $var1 \+ $var2`;;
2) echo "$var1 - $var2 =" `expr $var1 \- $var2`;;
3) echo "$var1 * $var2 =" `expr $var1 \* $var1`;;
4) echo "$var1 / $var2 =" `expr $var1 / $var2`;;
5) echo "Thank you";;
*) echo "Try again!";;

esac

done