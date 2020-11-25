#!/bin/bash
set -e

tests=$(dirname $(readlink -f $0))/../test
build=$(dirname $(readlink -f $0))/../build
out=$(dirname $(readlink -f $0))/../out

# command -v llvm-as >/dev/null 2>&1 || { echo >&2 "I require llvm-as but it's not installed.  Aborting."; exit 1; }
# type llvm-as >/dev/null 2>&1 || { echo >&2 "I require llvm-as but it's not installed.  Aborting."; exit 1; }
# hash llvm-as 2>/dev/null || { echo >&2 "I require llvm-as but it's not installed.  Aborting."; exit 1; }
type llvm-as-10 >/dev/null 2>&1 || { echo "Error: LLVM 10 toolchain missed, run 'setup.sh' first."; exit 1; }

if !(test -f $build/toy_compiler); then
    echo "Compiler binary is not found, please build first."
    exit 1
fi 
if !(test -d $out); then
    mkdir $out
fi

(cd $out && $build/toy_compiler $tests/test1.txt)    
echo "Info: AST, symbol table and LLVM IR code is in '$out'"   

(cd $out && rm -f clang1 clang2 ir.bc)
(cd $out && clang asm.s -o exec)    
echo "Info: Assembly code and executable is in '$out'"
