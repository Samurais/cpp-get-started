#! /bin/bash 
###########################################
#
###########################################

# constants
baseDir=$(cd `dirname "$0"`;pwd)
# functions

# main 
[ -z "${BASH_SOURCE[0]}" -o "${BASH_SOURCE[0]}" = "$0" ] || return
cd $baseDir
g++ -Wall -o main c5_main.cpp
./main
echo "Delete main in 2 seconds ..."
sleep 2
rm -rf main
