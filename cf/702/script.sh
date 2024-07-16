#!/bin/bash
if [ ! -f "cubes.txt" ]; then
    echo "Error: cubes.txt file not found."
    exit 1
fi

# Create a temporary file to store the modified C++ code
temp_file=$(mktemp)

# Copy the C++ code until the insertion point
awk '/put data here/ {print; print "        "; next} {print}' Cf.cpp > "$temp_file"

# Append the comma-separated numbers from cubes.txt
tr ',' '\n' < cubes.txt >> "$temp_file"

# Append the remaining C++ code after the insertion point
tail -n +$(awk '/put data here/ {print NR+1}' Cf.cpp) Cf.cpp >> "$temp_file"

# Replace the original Cf.cpp with the modified content
mv "$temp_file" Cf.cpp

echo "Data from cubes.txt has been inserted into Cf.cpp."
