test -e src/main.cpp && echo main.cpp FOUND
test -f src/main.cpp && echo main.cpp FOUND
test -d src/ && echo src directory FOUND
[ -e src/main.cpp ] && echo main.cpp FOUND
[ -f src/main.cpp ] && echo main.cpp FOUND
[ -d src/ ] && echo src directory FOUND
mkdir TOREMOVE
[ -d TOREMOVE/ ] && echo TOREMOVE directory FOUND
rm -rf TOREMOVE
[ -d TOREMOVE/ ] || echo TOREMOVE NOTFOUND
exit

