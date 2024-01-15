#!/bin/bash
# astroguard - A code auditing and streamlining tool for C programs to adhere to NASA JPL's Rule of 10
# Developed for Stellaryx Labs [stellaryxlabs.com]
# Written by Angelina Tsuboi [angelinatsuboi.com]
# Released under MIT License

# Default Values
hidebanner=0
version=0.1

# Default colors
red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
magenta='\033[0;35m'
cyan='\033[0;36m'
clear='\033[0m'

banner() {
    if [ $hidebanner == 0 ]; then
    color_text $(cat "./assets/banner.txt") magenta
    fi
}

# Adding color to terminal messages
print_color() {
    local text="$1"
    local color="$2"
    echo -e "${color}${text}${clear}"
}

# Installation Checking
# Checks for the following tools: gcc, gcov, gdb, and glov
print_color "Lauching astroguard 🚀" blue
print_color "Step 1 > Checking for installations" blue

if command -v gcc &> /dev/null; then
    echo "GCC is installed."
    # Check GCC version
    gcc_version=$(gcc --version | grep -oP 'gcc \K[^\s]+')
    echo "GCC version: $gcc_version"
else
    echo "GCC is not installed. Please install GCC before proceeding."
    exit 1
fi


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
gcc –Wall –pedantic –Wtraditional –Wshadow –Wpointer-arith –Wcast-qual –Wcast-align –Wstrict–prototypes –Wmissing–prototypes –Wconversion –std=iso9899:1999" $file_path" -o "$file_name_no_ext"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Execute the compiled program
    "./$file_name_no_ext"
else
    echo "Compilation failed."
fi
