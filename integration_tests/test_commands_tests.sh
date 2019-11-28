#!/bin/sh
### test_commands_test ###

test -e exit_command_tests.sh && echo EXIT TEST FOUND
test -f commented_command_tests.sh && echo COMMENT TEST FOUND
test -d DIRECTORYDOESNOTEXIST || echo this directory should not be found
[ -e exit_command_tests.sh ] && echo EXIT TEST FOUND
[ -f commented_command_tests.sh ] && echo COMMENT TEST FOUND
[ -d src/ ] || echo src DIRECTORY NOT FOUND
mkdir TOREMOVE
[ -d TOREMOVE/ ] && echo TOREMOVE directory FOUND
rm -rf TOREMOVE
[ -d TOREMOVE/ ] || echo TOREMOVE NOTFOUND
exit

