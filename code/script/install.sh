#!/bin/bash
set -e

project=$(dirname $(readlink -f $0))/..
cmake_dir=$project/cmake

if test -d $cmake_dir; then
    rm -rf $cmake_dir
fi    
mkdir $cmake_dir
(cd $cmake_dir && /usr/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" $project)