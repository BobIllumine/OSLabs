#!/bin/bash

file="ex2.txt"
lock="${file}.lock"

if [ ! -f $file ]
then
	echo 0 > $file
fi

while [ -f $lock ]
do
	:
done

echo 0 > $lock

last=`tail -n -1 ${file}`
write=`expr 1 + ${last}`

echo $write >> $file

rm $lock
exit
