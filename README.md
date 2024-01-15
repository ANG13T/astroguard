# astroguard
A simple code auditing and debugger tool based on gcc for embedded C aerospace applications adhering to NASA's JPL Rule of 10.


## About

## NASA JPL Rule of 10
Rule 1:
Rule 2:
Rule 3:
Rule 4:
Rule 5:
Rule 6:
Rule 7:
Rule 8:
Rule 9:
Rule 10:

## Optimized Compiler [run.sh]:
Compilation settings should be set to the most pedantic level of operation.
Run the run.sh with your chosen C file to compile your selected file with those warnings.

```
chmod +x run.sh
run.sh ./snippets/Rule_1.c
```

## Testing out Snippets
```
cd snippets
gcc Rule_4.c -o Rule_4
./Rule_4
```

## References
- https://security.web.cern.ch/recommendations/en/codetools/rats.shtml
- https://code.nasa.gov/#/guide
- https://betterprogramming.pub/the-power-of-10-nasas-rules-for-coding-43ae1764f73d
- https://en.wikipedia.org/wiki/The_Power_of_10:_Rules_for_Developing_Safety-Critical_Code
- https://nasa.github.io/fprime/UsersGuide/dev/code-style.html
- https://github.com/abougouffa/awesome-coding-standards/blob/master/jpl-c-1.0.pdf