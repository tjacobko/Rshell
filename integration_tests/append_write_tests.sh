#!/bin/sh
### append_tests_write ###

echo Hello World > integration_tests/scriptTest/scriptAppend.txt
ls >> integration_tests/scriptTest/scriptAppend.txt
ls -a >> testTXTdir/scriptAppend.txt
echo World Hello > integration_tests/scriptTest/scriptWrite.txt
echo Word Count | wc > integration_tests/scriptTest/scriptWrite.txt
exit
