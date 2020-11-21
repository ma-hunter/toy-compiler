#!/bin/bash
set -e

me=$(dirname $(readlink -f $0))
rm $me/../src/lex.yy.cc $me/../include/parser.tab.h $me/../src/parser.tab.cc

echo "Deleted static syntax analyser and parser."