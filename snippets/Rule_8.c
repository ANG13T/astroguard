/*
 NASA JPL Rule #8: Use the preprocessor sparingly
 The use of the preprocessor must be limited to the inclusion of header files and simple macro definitions.

 What is a preprocessor?
 A preprocessor is a program executed within the compilation program to perform basic text manipulation before the compilation process begins.

 Functions of a Preprocessor:
 - Macro handling. A marco is a block of code assigned with a specific name
 - File inclusion
 - Conditional compilation
 - Initialization of Pragma Directives. Provides additional information to the compiler to optimize its settings
*/

// adheres to rule (header file inclusion)
#include <stdio.h>

// adheres to rule (simple macro handling of a global variable)
#define PI 3.14159
#define BOOL

// violation of rule (advanced function macros)
#define STRINGIZE(x) #x
#define CONCATENATE(x, y) x ## y
#define SQUARE(x) ((x) * (x))

int main() {
#ifdef BOOL
    printf("BOOL is true\n");
#endif

    printf("Hello world %f\n", PI);

    return 0;
}