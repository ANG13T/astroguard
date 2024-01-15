# astroguard
A code auditing framework tool for aerospace applications adhering to NASA's JPL Rule of 10. Created for Embedded C applications.

## Outcomes
- Compiler Setting Adjustments
- Linter Reocmmendations and Warning Systems
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

Optimized Compiler [run.sh]:
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


## Routine Checking and Sanitation Warnings
