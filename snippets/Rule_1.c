/*
 Restrict all code to very simple control flow constructs
 - avoid gotos
 - setjmp or longjmp constructs
 - direct or indirect recursion

 Structured Control Flow Constructs in Programming 
 - Control Flow Contructs allow programmers to execute the code flow in an organized manner.
 This paardigm of writing code makes it more readable and less error prone.
 Key Control Flow Structures Include:
 - Sequential Execution (code is executed line-by-line)
 - Conditional Statements (alter the flow of execution based on a specified condition)
    - if statements: Executes a block of code if a specified condition is true
    - else statements: Provides an alternative block of code to execute if the condition in an if statement is false
    - switch statements: Allows for multi-way branching based on the value of an expression
 - Looping (repeat a block of code multiple times)
    - for loops: Execute a block of code a specified number of times
    - while loops: Continue executing a block of code as long as a specified condition is true
    - do-while loops: Similar to while loops, but the block of code is guaranteed to execute at least once
 - Structured Subroutines & Functions
    - A subroutine is a generic term for a block of code that performs a specific task
    - It is a broader term that encompasses both functions and procedures
    - A function is a type of subroutine that returns a value
    - A procedure is a type of subroutine that does not return a value

 Recursion in Programming:
 Recursion is when a function calls itself to solve a problem. It has two things: base case and a recursive case.
 - Direct recursion is when a function directly calls itself within its own block of code
 - Indirect recursion is when a function calls another function which then calls the first function again

setjmp and longjmp Constructs
Non-local jump, allowing you to jump from one part of your program to another, even across function calls
- setjmp is a function that saves the current state of the program's execution
- longjmp is a function that performs the actual jump back to the point saved by setjmp 
*/
#include <stdio.h>
#include <setjmp.h>

jmp_buf jump_buffer;

int main()
{
    // Case 1: NO GOTOs
   checkIfOdd(5);
   checkIfOdd_Fixed(5);

    // Case 2: NO Recursion (Direct)
    // Case 3: NO Recusrion (Indirect)
    // Case 4: NO JMP Buffer Commands
}

/*
 TASK: Demonstrates GOTO 
 GOTOs within programming 
*/
void checkIfOdd(int value) {
    if (value % 2 == 1) {
        go_to odd_handling;
    }

    printf("Value is EVEN!");
    return;

    odd_handling:
        printf("This is an ODD value")
}

/*
 TASK: Fixing the GOTO Code
*/
void checkIfOdd_Fixed(int value) {
    if (value % 2 == 1) {
        printf("This is an ODD value");
        return;
    }

    printf("Value is EVEN!");
}

/*
 TASK: Demonstrates direct recursion
 Recursion within programming 
*/
int checkFactorialDirect(int value) {
    if (value == 1) { // base case
        return 1;
    } else { // recusive case
        return value * checkFactorialDirect(value - 1);
    }
}

/*
 TASK: Demonstrates indirect recursion (0 = even and 1 = odd)
 Recursion within programming 
*/

int checkOddIndirect(int value) {
    if (value == 0) { // base case
        return 1;
    } else { // recursive case
        return checkEvenIndirect(value - 1);
    }
}

int checkEvenIndirect(int value) {
    if (value == 0) { // base case
        return 0;
    } else { // recursive case
        return checkOddIndirect(value - 1);
    }
}

/*
 TASK: Demonstrate longjmp and setjmp
*/

void testJumpBuffer() {
    int jump_result = setjmp(jump_buffer);

    if (jump_result == 0) {
        // Code here is executed on the first pass
        printf("First pass!\n");
    } else {
        // Code here is executed if longjmp is called
        printf("Resumed after longjmp with value %d\n", jump_result);
    }
}

int executeJumpBuffer() {
    testJumpBuffer();
    int result = 30;
    longjmp(jump_buffer, result);

    printf("This line is never reached\n");

    return 0;
}
