#!/bin/sh
MYPIPE=mypipe-$$
mkfifo $MYPIPE
cat $MYPIPE | nc -l $1 | /home/jae/cs3157-pub/bin/mdb-lookup-cs3157 > $MYPIPE
rm -f $MYPIPE

