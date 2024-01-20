#!/bin/bash
# astroguard - A code auditing and streamlining tool for C programs to adhere to NASA JPL's Rule of 10
# Developed for Stellaryx Labs [stellaryxlabs.com]
# Written by Angelina Tsuboi [angelinatsuboi.com]
# Released under MIT License

set -- $GRARGS $@
set -e
set -o pipefail

# Default Values
hidebanner=0
version=0.1
output_name=""
file_name=""
file_path=""
file_name_no_ext=""
file_path_no_ext=""

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
    IFS=
    while IFS= read -r line; do
        print_color "$line" magenta
    done < "./assets/banner.txt"
    fi
}

about() {
    cat "./assets/help.txt"
}

# Adding color to terminal messages
print_color() {
    local text="$1"
    local color="$2"
    local selected_color="$blue"

    case $color in
        red)
            selected_color="$red"
        ;;
        green)
            selected_color="$green"
        ;;
        yellow)
            selected_color="$yellow"
        ;;
        blue)
            selected_color="$blue"
        ;;
        magenta)
            selected_color="$magenta"
        ;;
        cyan)
            selected_color="$cyan"
        ;;
    esac

    echo -e "${selected_color}${text}${clear}"
}

# Step #1
# Installation Checking
# Checks for the following tools: gcc, gcov, gdb, and lcov

installation() {
    print_color "Lauching astroguard 🚀" cyan
    print_color "Step 1 > Checking for installations" cyan

    if command -v gcc &> /dev/null; then
        print_color "GCC is installed!"
    else
        print_color "GCC is not installed. Please install GCC before proceeding." red
        exit 1
    fi

    if command -v gcov &> /dev/null; then
        print_color "gcov is installed!"
    else
        print_color "gcov is not installed. Please install gcov before running this script." red
        exit 1
    fi

    if command -v lcov &> /dev/null; then
        print_color "lcov is installed!"
    else
        print_color "lcov is not installed. Please install lcov before running this script." red
        exit 1
    fi

    if command -v gdb &> /dev/null; then
        print_color "gdb is installed!"
    else
        print_color "gdb is not installed. Please install gdb before running this script." red
        exit 1
    fi
}

# Step #2
# Compiles the C program
# Compilations settings set to the most pedantic level

compile() {
    print_color "Step 2 > Compiling Input File" cyan
    # Compile the C file
    gcc -Wall -pedantic -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wconversion -std=iso9899:1999 --coverage "${file_path}" -o "${file_path_no_ext}"

    # Check if compilation was successful
    if [ $? -eq 0 ]; then
        # Execute the compiled program
        "${file_path_no_ext}"
    else
        print_color "Compilation failed." red
    fi
}

# Step #3
# Generate code coverage report using gcov

coverage() {
    print_color "Step 3 > Generating Coverage Report" cyan
    gcov "${file_name}"
}

# Step #4
# Generate line coverage report using lcov

line_coverage() {
    print_color "Step 4 > Generating Line Coverage Report" cyan
    lcov -c --directory . --output-file main_coverage.info
}

# Step #5
# Generate HTML coverage report using genhtml

gen_html() {
    print_color "Step 5 > Generating HTML Coverage Report" cyan
    genhtml main_coverage.info --output-directory out
}


while getopts "bBho:" flag; do
  case $flag in
    b)
        hidebanner=1
    ;;
    h)
        about
        exit 1
    ;;
    o)
        output_name="$OPTARG"
    ;;
    \?)
        about
        exit 2
    ;;
  esac
done

shift $((OPTIND-1))

file_path="$1"
file_name=$(basename -- "$file_path")
file_name_no_ext="${file_name%.*}"
file_path_no_ext="${file_path%.*}"
echo $file_path_no_ext
file_ext="${file_path: -1}"

# Check if a file path is provided
if [ -z "$file_path" ]; then
    print_color "Error: File path not provided." red
    exit 1
elif [ "${file_ext}" != "c" ]; then
    print_color "Error: File must be C." red
    exit 1
fi

banner
installation
compile
coverage
line_coverage
gen_html
print_color "Finished running all reports 🚀" cyan 
exit