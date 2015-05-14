#!/bin/bash

while getopts xyz: arguments 2> /dev/null
do
case $arguments in
	x) echo "option x";;
	y) echo "option y";;
	z) echo "option z with arg. $OPTARG";;
	/?) echo "Usage: optdemo [-xy] [-z argment]"
exit 1;;
esac
done

echo "/$OPTIND is $OPTIND /$OPTERR is $OPTERR"
