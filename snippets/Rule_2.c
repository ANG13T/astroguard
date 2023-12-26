/*
 NASA JPL Rule #2:
 All loops must have fixed bounds. This prevents runaway code.
 All loops should be bound by a hard upper bound that is an integer not a pointer
 The point of this is to avoid runaway code: section of code enters an unintended, infinite loop or consumes excessive resources

 An exception is allowed for the use of a single non-terminating loop per task or thread where requests are received and processed
*/ 

#include <stdio.h>
#include <stdlib.h>

void fixedBoundLoop() {
    for (int i = 0; i < 10; ++i) {
        printf("Iteration %d\n", i);
    }
}

void infiniteLoop() {
    // infinite loop rule violation
    int i = 0;
    while (1) {
        printf("Iteration %d\n", i);
    }
}

void noBoundsExample(int size) {
    // Violating the rule with a loop that depends on external input
    for (int i = 0; i < size; ++i) {
        printf("Iteration %d\n", i);
    }
}

// SNIPPETS OF RUNAWAY CODE

// this will consume system resources and preventing the program from progressing
void infiniteViolation() {
  while (1) {
    printf("Running Forever... \n");
  }
}

// this will consume the call stack and trigger a stack overflow
int infiniteRecusionViolation(int value) {
  return 1 + infiniteRecusionViolation(value + 1);
}

void badConstraintsViolation(int size) {
  for (int i = 0; i < size; ++i) {
     printf("Value %d\n", i);
  }
}

// Failing to release allocated memory can lead to a gradual increase in memory usage, eventually causing the program to exhaust available memory resources
void memoryLeakViolation() {
  int* dynamicArray = malloc(sizeof(int) * 100);
  // Missing free(dynamicArray), causing a memory leak
}

void logicalCheckingNullViolation(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        int currentElement = array[i];

        // Do some processing with the current element
        printf("Processing element %d\n", currentElement);

        // Simulating a condition where a null value should not break out of the loop
        if (currentElement == 0) {
            // Avoid using a logical check for null to break out of the loop
            // Instead, continue processing or use explicit loop control mechanisms
            printf("Encountered a null-like value; continuing...\n");
        }

        // Continue processing other elements
        printf("Processing continues...\n");

        // Simulating additional logic within the loop
        if (currentElement == 5) {
            printf("Found the element 5; breaking out of the loop\n");
            break; // Explicitly break out of the loop when a specific condition is met
        }
    }
}


int main() {
  fixedBoundLoop();

  int exampleArray[] = {1, 2, 0, 4, 5, 6, 7};

  logicalCheckingNullViolation(exampleArray, sizeof(exampleArray) / sizeof(exampleArray[0]));
}
