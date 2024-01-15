/*
 NASA JPL Rule #9: Limit pointer use to a single dereference, and do not use function pointers

 What is a Pointer?
 A variable that stores the memory address of another variable value

 Pointer Concepts:
 1. Declaration
 int *pointer;

 2. Initialization (in this example, the address of value is stored inside the pointer variable)
 int value = 20;
 int *pointer = &value;

 3. Dereferencing (Dereferincing allows you to access the value stored at the memory address pointed to by the pointer)
 int pointer_value = *pointer;

 4. Pointer Arithmetic (you can navigate to various points of memory by incrementing and decrementing the pointer value)
 int example[3] = {1, 2, 3};
 int *pointer = example;
 int thirdElement = *(pointer + 2); // this shifts the memory address 2 units to the right

 5. Null Pointers (pointer assigned to NO location)
 int *pointer = NULL;
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// This function does NOT follow the rule because it uses a double dereference for a pointer
// This function gets the product of A and B pointers
int codeViolation(int **ptrA, int **ptrB) {
    int a = **ptrA;  // Double dereference to get the value pointed by ptrA
    int b = **ptrB;  // Double dereference to get the value pointed by ptrB

    return a * b;
}

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x + y;
}

// This function does NOT follow the rule because it uses function pointers
int codeViolation2(int *a, int *b, bool is_additive) {
    // Function pointers for different operations
    int (*operationFunc)(int, int);

    if (is_additive == true) {
        operationFunc = add;
    } else {
        operationFunc = subtract;
    }

    int result = (*operationFunc)(*a, *b);
    return result;
}

// This function DOES follow the rules because it does NOT use function pointers and limits pointer usage to a single dereference
// This code swaps the addresses of a and b
void ruleAdherance(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 5, num2 = 3;

    // Pointers to the variables num1 and num2
    int *ptrNum1 = &num1;
    int *ptrNum2 = &num2;
    int result = codeViolation(&ptrNum1, &ptrNum2);

    printf("Product of num1 and num2: %d\n", result);

    bool val = true;
    int result2 = codeViolation2(&num1, &num2, val);

    printf("Sum of num1 and num2: %d\n", result2);

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Pass the addresses of num1 and num2 to the swap function
    ruleAdherance(&num1, &num2);

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
}