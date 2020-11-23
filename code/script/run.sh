#!/bin/bash
# TODO: Need to repair
set -e

tests=$(dirname $(readlink -f $0))/../test
build=$(dirname $(readlink -f $0))/../build
out=$(dirname $(readlink -f $0))/../out

if !(test -f $build/toy_compiler); then
    echo "Binary is not found, please build first."
    exit 1
fi  
if !(test -d $tests/out); then
    mkdir $tests/out
fi
if !(test -d $tests/err); then
    mkdir $tests/err
fi
if !(test -d $out); then
    mkdir $out
fi
(cd $out && $build/toy_compiler $tests/test1.txt > $tests/out/test1.out 2> $tests/err/test1.err)          
