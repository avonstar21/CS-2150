#!/bin/bash
#echo 'Hello, world!'
file="$1"
#echo dictName
file2="$2"
#echo $gridName
RUNNING_TIME1=`./a.out $file $file2 | tail -1`
RUNNING_TIME2=`./a.out $file $file2 | tail -1`
RUNNING_TIME3=`./a.out $file $file2 | tail -1`
RUNNING_TIME4=`./a.out $file $file2 | tail -1`
RUNNING_TIME5=`./a.out $file $file2 | tail -1`
echo $((RUNNING_TIME1 + RUNNING_TIME2 + RUNNING_TIME3 + RUNNING_TIME4 + RUNNING_TIME5)/5)
