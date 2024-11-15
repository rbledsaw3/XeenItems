#!/usr/bin/env bash

# Build the project
echo "Building the project..."
echo "Creating the build directory..."
mkdir -p build
cd build
echo "Compiling source..."
g++ ../src/main.cpp -o main
echo "Build complete!"
echo "Run the program with ./main"

