#!/bin/bash

function usage()
{
	echo -ne "Usage: findfile arg\n"
	echo -ne "to find a file named arg under the current directory.\n"
}

if [ "$1" == "" ] 
then
	usage 
	exit
elif [ "$1" == "-l" ]
then
	files=$(find . -name $2)
	for i in ${files[@]}
        do 
		ls -l $i
	done
else 
	find . -name $1
fi

