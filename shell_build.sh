#!/bin/bash


#!/bin/bash

cmake -S . -B build

if [ $? -eq 0 ]; then
    echo "First command executed successfully. Proceeding with the build."
    cmake --build build
else
    echo "Error: First command failed. Aborting the build."
fi

