#!/bin/bash
set -e

tests=$(dirname $(readlink -f $0))/../test
build=$(dirname $(readlink -f $0))/../build

if !(test -f $build/toy_compiler); then
    echo "Binary is not found, please build first."
    exit 1
fi   
for ii in {1..100..1}
do 
    if test -f `$tests/test$ii.txt`; then
        $build/toy_compiler `$tests/test$ii.txt` > `$tests/out/test$ii.out` 2> `$tests/err/test$ii.err`
    else 
        echo "Test completed"    
        break
    fi
done            
