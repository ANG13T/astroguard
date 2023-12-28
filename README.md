# astroguard
A code auditing framework tool for aerospace applications adhering to NASA's JPL Rule of 10. Created for Embedded C applications.

## Outcomes
- VSCode Extension + Compiler Setting Adjustments
- YouTube Series with Slideshows (2min each) 12 video series [1 - 2 days]
- 10 Case Study Files and README
- Make into expanded PDF for sale on GumRoad
- Make a video about this on Retia YouTube channel

https://github.com/abougouffa/awesome-coding-standards/blob/master/jpl-c-1.0.pdf

https://nasa.github.io/fprime/UsersGuide/dev/code-style.html

https://en.wikipedia.org/wiki/The_Power_of_10:_Rules_for_Developing_Safety-Critical_Code

https://betterprogramming.pub/the-power-of-10-nasas-rules-for-coding-43ae1764f73d

https://code.nasa.gov/#/guide

Inspiration:
https://security.web.cern.ch/recommendations/en/codetools/rats.shtml

Optimized Compiler:

Rule 2 (routine checking)
All code shall always be compiled with all compiler warnings enabled at the highest warning level available, with no errors or warnings resulting. All code shall further be verified with a JPL approved state-of-the-art static source code analyzer, with no errors or warnings resulting. [MISRA-C:2004 Rule 21.1]
This rule should be considered routine practice, even for non-critical code development. Given compliance with Rule 1, this means that the code should compile without errors or warnings issued with the standard gcc compiler, using a command line with minimally the following option flags:
      gcc –Wall –pedantic –std=iso9899:1999 source.c
A suggested broader set of gcc compiler flags includes also:
      -Wtraditional
      -Wshadow
      -Wpointer-arith
      -Wcast-qual
      -Wcast-align
      -Wstrict-prototypes
      -Wmissing-prototypes
      -Wconversion
