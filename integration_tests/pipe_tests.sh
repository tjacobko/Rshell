#!/bin/sh
### pipe_tests ###

ls | wc
echo WC is word count | wc
ls | cat | wc
ls -a | wc
cat < test.txt | tr a-z A-Z | tee scriptOutputFile
exit
