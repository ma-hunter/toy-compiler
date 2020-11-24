#!/bin/bash

tests=$(dirname $(readlink -f $0))/../test
build=$(dirname $(readlink -f $0))/../build
out=$(dirname $(readlink -f $0))/../out

if !(test -f $build/toy_compiler); then
    echo "Binary is not found, please build first."
    exit 1
fi  
if !(test -d $out); then
    mkdir $out
fi
for ii in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
do
    echo "Info: Test $ii start:"
    echo ""
    (cd $out && $build/toy_compiler $tests/test$ii.txt) 
    if $? != "0"; then
        echo "Warn: Return value is not 0."
    fi    
    echo ""
    echo "Info: Test $ii end."
    echo "" 
done  
echo "Info: AST, symbol table and LLVM IR code is in '$out'"      
