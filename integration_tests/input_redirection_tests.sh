#!/bin/sh
### input_redirection_tests ###

cat < scriptTest/scriptPipe.txt
cat < scriptTest/scriptAppend.txt
wc < scriptTest/scriptPipe.txt
cat < scriptTest/scriptWrite.txt
tr A-Z a-z < scriptTest/scriptWrite.txt
exit
