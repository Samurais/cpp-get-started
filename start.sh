#! /bin/bash 
###########################################
# Start App
###########################################

# constants
baseDir=$(cd `dirname "$0"`;pwd)
execApp=$baseDir/cmake-build-debug/bin/restapi
# functions

# main 
[ -z "${BASH_SOURCE[0]}" -o "${BASH_SOURCE[0]}" = "$0" ] || return
$execApp
