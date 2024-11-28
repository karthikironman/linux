#!/bin/bash

SRC_DIR=.
BUILD_DIR=build
mkdir -p $BUILD_DIR
SRC_FILES="main.c utils.c menu.c"
BUILD_COMMANDS=(
  "gcc $SRC_FILES -o $BUILD_DIR/project1_x86_64"
  "arm-linux-gnueabi-gcc $SRC_FILES -o $BUILD_DIR/project1_arm32"
  "aarch64-linux-gnu-gcc $SRC_FILES -o $BUILD_DIR/project1_aarch64"
)

for ((i=0; i<${#BUILD_COMMANDS[@]}; i++)); do
  echo "Building for ${i+1}..."
  eval ${BUILD_COMMANDS[$i]}
done

echo "All builds successful!"

: '
The below commands are automated in this script file
gcc main.c utils.c menu.c -o build/project1_x86_64
#arm-linux-gnueabi-gcc main.c utils.c menu.c -o build/project1_arm32
#aarch64-linux-gnu-gcc main.c utis.c menu.c -o build/project1_aarch64
'