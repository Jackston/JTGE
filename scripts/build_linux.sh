#!/bin/bash

BUILD_DIR="build"
BIN_DIR="bin"
LIB_DIR="lib"

while getopts "cexh" opt
do
case $opt in
    c) rm -rf ./${BUILD_DIR} ./${BIN_DIR} ./${LIB_DIR} ;;
    e) BUILD_EXAMPLES="-DBUILD_EXAMPLES=ON" ;;
    x) rm -rf ./${BUILD_DIR} ./${BIN_DIR} ./${LIB_DIR}
       exit
       ;;
    h) echo "Options: "
       echo "-c - clean build"
       echo "-e - build examples"
       echo "-x - cleanup, remove all build artifacts"
       exit
       ;;
esac
done

mkdir -p $BUILD_DIR
mkdir -p $BIN_DIR
mkdir -p $LIB_DIR
cmake -H. -B${BUILD_DIR} ${BUILD_EXAMPLES}
cmake --build ./${BUILD_DIR}