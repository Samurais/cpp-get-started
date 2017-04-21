#! /bin/bash 
###########################################
# Build Project
###########################################

# constants
baseDir=$(cd `dirname "$0"`;pwd)
debugDir=$baseDir/cmake-build-debug
# functions

# main 
[ -z "${BASH_SOURCE[0]}" -o "${BASH_SOURCE[0]}" = "$0" ] || return

# generate cmake files
if [ -d $debugDir ]; then
    cd $debugDir
else
    mkdir $debugDir
    cd $debugDir && cmake -DCMAKE_BUILD_TYPE=Debug ..
fi

cmake --build . -- -j 4

