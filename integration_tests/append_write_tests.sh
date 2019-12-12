#!/bin/sh
### append_tests_write ###

echo Hello World >> scriptTest/scriptAppend.txt
ls >> scriptTest/scriptAppend.txt
ls -a >> scriptTest/scriptAppend.txt
echo World Hello > scriptTest/scriptWrite.txt
echo Word Count | wc > scriptTest/scriptWrite.txt
exit
