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
g++ -Wall -o kvstore kvstore.cpp
./kvstore
echo "Delete kvstore in 2 seconds ..."
sleep 2
rm -rf kvstore
