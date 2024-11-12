#!/bin/bash

# Clean previous builds
make clean

# Build the library
make

# Compile the test program
gcc -o test_ft test_ft.c -L. -lft

# Run the test program
echo "Running tests..."
./test_ft

# Check the exit code to confirm all tests passed
if [ $? -eq 0 ]; then
    echo "All tests passed!"
else
    echo "Some tests failed."
fi
