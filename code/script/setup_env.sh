#!/bin/bash
set -e

sudo apt-get update

# sudo apt remove -y --purge llvm bison flex
sudo apt install -y llvm bison flex
sudo apt install cmake gcc clang gdb build-essential

echo "Environment and basic dependencies has set up."