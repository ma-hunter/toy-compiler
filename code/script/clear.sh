#!/bin/bash
set -e

me=$(dirname $(readlink -f $0))
rm $me/../src/lex.yy.cc $me/../include/parser.tab.h $me/../src/parser.tab.cc
rm -rf $me/../build/ $me/../cmake

echo "Deleted cmake files and syntax parser."