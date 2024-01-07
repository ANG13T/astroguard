#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <path_to_c_file>"
    exit 1
fi

# Extract the file name and remove the extension
file_path="$1"
file_name=$(basename -- "$file_path")
file_name_no_ext="${file_name%.*}"

# Compile the C file
gcc –Wall –pedantic -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion –std=iso9899:1999" $file_path" -o "$file_name_no_ext"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Execute the compiled program
    "./$file_name_no_ext"
else
    echo "Compilation failed."
fi
