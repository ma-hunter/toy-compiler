#!/bin/bash
set -e

me=$(dirname $(readlink -f $0))
(cd $me/../cmake/usr/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" $me/..)