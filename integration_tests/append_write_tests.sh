#!/bin/sh
### append_tests_write ###

echo Hello World > testTXTdir/scriptAppend.txt
ls >> testTXTdir/scriptAppend.txt
ls -a >> testTXTdir/scriptAppend.txt
echo World Hello > testTXTdir/scriptWrite.txt
echo Word Count | wc > testTXTdir/scriptWrite.txt
exit
