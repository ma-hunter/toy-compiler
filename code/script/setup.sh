#!/bin/bash

# If apt is blocked in your local, you can:
# - Install package manually and delete command below
# - Use proxy before run this script
set -e

## Step 1. import sources of LLVM for APT

# Backup apt's sources.list
sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak
sudo chmod 666 /etc/apt/sources.list

# Add apt source of LLVM for Debian 10 
sudo echo '
deb http://apt.llvm.org/buster/ llvm-toolchain-buster main
deb-src http://apt.llvm.org/buster/ llvm-toolchain-buster main 
# 10 
deb http://apt.llvm.org/buster/ llvm-toolchain-buster-10 main 
deb-src http://apt.llvm.org/buster/ llvm-toolchain-buster-10 main 
# 11 
deb http://apt.llvm.org/buster/ llvm-toolchain-buster-11 main 
deb-src http://apt.llvm.org/buster/ llvm-toolchain-buster-11 main
' >> /etc/apt/sources.list

# Add apt source of LLVM for Ubuntu 18.04
sudo echo '
deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic main 
deb-src http://apt.llvm.org/bionic/ llvm-toolchain-bionic main 
# 10 
deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-10 main 
deb-src http://apt.llvm.org/bionic/ llvm-toolchain-bionic-10 main 
# 11 
deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-11 main 
deb-src http://apt.llvm.org/bionic/ llvm-toolchain-bionic-11 main
' >> /etc/apt/sources.list

# Add apt source of LLVM for Ubuntu 20.04
sudo echo '
deb http://apt.llvm.org/focal/ llvm-toolchain-focal main 
deb-src http://apt.llvm.org/focal/ llvm-toolchain-focal main 
# 10
deb http://apt.llvm.org/focal/ llvm-toolchain-focal-10 main 
deb-src http://apt.llvm.org/focal/ llvm-toolchain-focal-10 main 
# 11 
deb http://apt.llvm.org/focal/ llvm-toolchain-focal-11 main
deb-src http://apt.llvm.org/focal/ llvm-toolchain-focal-11 main
' >> /etc/apt/sources.list

# get archive signature
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -

sudo apt-get update

## Step 2. install dependencies and old version of LLVM

# sudo apt remove -y --purge llvm bison flex
sudo apt install -y bison flex
sudo apt install cmake gcc clang gdb build-essential
sudo apt remove llvm-7 llvm-7-dev llvm-8 llvm-8-dev llvm-10 llvm-10-dev 
sudo apt install libllvm-10-ocaml-dev libllvm10 llvm-10 llvm-10-dev llvm-10-doc llvm-10-examples llvm-10-runtime
sudo apt-get install zlib1g-dev

echo "Environment and basic dependencies has set up."
