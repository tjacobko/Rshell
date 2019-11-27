(echo Hello World)
(echo Hi && git status) || echo Bye
echo Yeeee || (echo WEEE && echo ZEEE) 
(ls -a) && (ls -l) && (ls -i)
(echo Yee && echo Haw) || ls -a
(ls -a || ls -l) && mkdir TESTDIR && echo Created TESTDIR
(ls -a && rm -rf TESTDIR) && echo Delted TESTDIR || echo Failed to Delete
exit
