#!/bin/bash
set -e

me=$(dirname $(readlink -f $0))
/usr/bin/cmake --build $me/../cmake --target toy_compiler -- -j 4