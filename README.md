<img src="https://github.com/ANG13T/astroguard/blob/main/assets/banner.png" alt="astroguard Banner" width="800"/>

# astroguard
A simple code auditing and profiling tool based on gcc for C programs to adhere to NASA's JPL Rule of 10.
C programs can be specified into the tool and is run through a sequence of **gcc -> gcov -> glov** to obtain code coverage and compilation information.

## Usage 🚀
```
git clone https://github.com/ANG13T/astroguard
cd astroguard
chmod +x astroguard.sh
astroguard.sh ./snippets/Rule_1.c
```

Make sure you have the following installed on your machine:
`gcc, gcov, and lcov`

### Preview 🪐
<img src="https://github.com/ANG13T/astroguard/blob/main/assets/images/preview.png" alt="astroguard Image" width="600"/>

## NASA JPL Rule of 10 ✨

[Rule 1](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_1.c): Avoid complex flow constructs, such as goto and recursion.

[Rule 2](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_2.c): All loops must have fixed bounds. This prevents runaway code.

[Rule 3](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_3.c): Avoid heap memory allocation.

[Rule 4](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_4.c): Restrict functions to a single printed page.

[Rule 5](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_5.c): Use a minimum of two runtime assertions per function.

[Rule 6](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_6.c): Restrict the scope of data to the smallest possible.

[Rule 7](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_7.c): Check the return value of all non-void functions, or cast to void to indicate the return value is useless.

[Rule 8](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_8.c): Use the preprocessor sparingly.

[Rule 9](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_9.c): Limit pointer use to a single dereference, and do not use function pointers.

[Rule 10](https://github.com/ANG13T/astroguard/blob/main/snippets/Rule_10.c): Compile with all possible warnings active; all warnings should then be addressed before release of the software.

## GCC Usage
GCC (GNU Compiler Collection) is a compiler for C programs maintained by the GNU Project. It turns your C code into binary which is then interpreted by a computer. It performs static analysis and debugging. 

## Optimized Compiler [astroguard.sh]:
astroguard settings should be set to the most pedantic level of operation.
Run the astroguard.sh with your chosen C file to compile your selected file with those warnings.

## Testing out Snippets 🔨
```
cd snippets
gcc Rule_4.c -o Rule_4
./Rule_4
```

## References 🔬
- https://security.web.cern.ch/recommendations/en/codetools/rats.shtml
- https://code.nasa.gov/#/guide
- https://betterprogramming.pub/the-power-of-10-nasas-rules-for-coding-43ae1764f73d
- https://en.wikipedia.org/wiki/The_Power_of_10:_Rules_for_Developing_Safety-Critical_Code
- https://nasa.github.io/fprime/UsersGuide/dev/code-style.html
- https://github.com/abougouffa/awesome-coding-standards/blob/master/jpl-c-1.0.pdf
- https://github.com/SakuGlumoff/DebugPrint-GCC/tree/master

## Contributing ✨
astroguard is open to any contributions. Please fork the repository and make a pull request with the features or fixes you want to implement.

#### Suggested Features
- An output directory that stores all output files from the astroguard.sh script which can be specified via path `-o`

## Support 💜
If you enjoyed astroguard, please consider becoming a sponsor in order to fund my future projects.

To check out my other works, visit my [GitHub profile](github.com/ANG13T).

To check out Stellaryx Labs, visit [stellaryxlabs.com](stellaryxlabs.com)
