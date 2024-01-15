/*
 NASA JPL Rule #10: Compile with all possible warnings active; all warnings should then be addressed before release of the software

 This rule should be considered routine practice, even for non-critical code development. Given compliance with Rule 1, this means that the code should compile without errors or warnings issued with the standard gcc compiler, using a command line with minimally the following option flags:
      gcc –Wall –pedantic –std=iso9899:1999 source.c

 Flag Reference: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wmissing-prototypes

 Flag Defitnitions and Functions:
      -Wall = This flag enables a comprehensive set of warnings
      -pedantic = This flag enables strict adherence to the chosen C language standard
      -Wtraditional = Warn about certain constructs that behave differently in traditional and ISO C
      -Wshadow = warn whenever a local variable shadows another local variable
      -Wpointer-arith = warn if anything depends upon the size of a function or of void
      -Wcast-qual = warn whenever a pointer is cast to remove a type qualifier
      -Wcast-align = warn whenever a pointer is cast such that the required alignment of the target is increased
      -Wstrict-prototypes = warn if a function is declared or defined without specifying the argument types
      -Wmissing-prototypes = Warn if a global function is defined without a previous prototype declaration
      -Wconversion = warn for implicit conversions
*/
int main() {
    return 0;
}