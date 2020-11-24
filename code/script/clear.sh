#!/bin/bash
set -e

me=$(dirname $(readlink -f $0))
rm -f $me/../src/lex.yy.cc $me/../include/parser.tab.h $me/../src/parser.tab.cc $me/../config.y.output
rm -rf $me/../build/ $me/../cmake
rm -rf $me/../test/log/ $me/../test/err/ $me/../test/out/ $me/../out/

echo "Deleted cmake files, test temporaries and syntax parser."