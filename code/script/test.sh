#!/bin/bash
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
for ii in $(seq 1 20)
do 
    if test -f `$tests/test$ii.txt`; then
        (cd $out && $build/toy_compiler `$tests/test$ii.txt` > `$tests/out/test$ii.out` 2> `$tests/err/test$ii.err`)
    else 
        echo "Test completed"    
        break
    fi
done            
