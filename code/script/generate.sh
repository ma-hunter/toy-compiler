#!/bin/bash
set -e

me=$(dirname $(readlink -f $0))

flex -o $me/../src/lex.yy.cc $me/../config/lex.l
bison --defines=$me/../include/parser.tab.h --output=$me/../src/parser.tab.cc $me/../config/parser.y

echo "Syntax analyser and parser generated successfully."