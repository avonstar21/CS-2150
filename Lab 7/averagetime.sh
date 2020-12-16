#!/bin/bash
echo "enter the exponent for counter.cpp:"
read exp
sum=0
n=1
for((counter=5; counter>0; counter--))
do
    echo "Running iteration $n..."
    RUNNING_TIME=`./a.out $exp | tail -1`
    echo "time taken: $RUNNING_TIME ms"
    ((sum=$sum+$RUNNING_TIME))
if [ $n -eq 5 ];
then
    echo "$n iterations took $sum ms"
    ((avg=$sum/5))
    echo "Average time was $avg ms"
else
    ((n=1+$n))

fi
done


   

   



