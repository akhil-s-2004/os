#!/bin/bash
echo "Enter number of terms: "
read num
echo "Fibonacci series with $num terms"
num1=0
num2=1
echo $num1
echo $num2
for(( i=2;i<num;i++ ))
do
        a=$(($num1 + $num2))
        num1=$num2
        num2=$a
        echo $a
done
