#!/bin/bash

# Set the source directory
SRC_DIR=.

# Set the build directory
BUILD_DIR=build

# Create the build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Define the source files
SRC_FILES=(main.c utils.c menu.c)

# Define the build commands
BUILD_COMMANDS=(
  "gcc ${SRC_FILES[@]} -o $BUILD_DIR/project1_x86_64"
  "arm-linux-gnueabi-gcc ${SRC_FILES[@]} -o $BUILD_DIR/project1_arm32"
  "aarch64-linux-gnu-gcc ${SRC_FILES[@]} -o $BUILD_DIR/project1_aarch64"
)

# Loop through the build commands
for ((i=0; i<${#BUILD_COMMANDS[@]}; i++)); do
  echo "Building for ${i+1}..."
  eval ${BUILD_COMMANDS[$i]}
done

# Print a success message
echo "All builds successful!"