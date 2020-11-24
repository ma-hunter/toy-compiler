#!/bin/bash
set -e

me=$(dirname $(readlink -f $0))

flex -o $me/../src/lex.yy.cc $me/../config/lex.l
bison --defines=$me/../include/parser.tab.h --output=$me/../src/parser.tab.cc $me/../config/parser.y
(cd $me/../config && bison -y -v parser.y > out 2> err)
(cd $me/../config && rm -f y.tab.c out err)

echo "Syntax analyser and parser generated successfully."