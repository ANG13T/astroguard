/*
 NASA JPL Rule #5: Use a minimum of two runtime assertions per function

 What is a runtime assertion?
A runtime assertion is a conditional statement that should always result to true at that line in the program
It is used to catch potential errors early on in that program (debugging and testing)
*/

#include <stdio.h>
#include <assert.h>

// Rule Violation: does not include runtime assertions for extra validation
int codeViolation() {
    double luminosities[] = {1.2, 5.8, 20.3, 100.0, 5000.0};
    size_t size = sizeof(luminosities) / sizeof(luminosities[0]);

    // Luminosity value to check
    double luminosityToCheck = 20.3;

    // Violation: No assertion to check size of array

    for (size_t i = 0; i < size; ++i) {
        // Violation: no checking for luminosity in the array
        printf("Luminosity Value: %f", luminosities[i]);
    }

    // If the function reaches this point, the value is not present in the array
    return 0;
}

// Rule Adherence: includes two runtime assertions for value checking
int codeOptimization() {
    double luminosities[] = {1.2, 5.8, 20.3, 100.0, 5000.0};
    size_t size = sizeof(luminosities) / sizeof(luminosities[0]);

    // Luminosity value to check
    double luminosityToCheck = 20.3;

    // Assertion: Ensure that the array is not empty
    assert(size > 0 && "Array must have at least one element");

    for (size_t i = 0; i < size; ++i) {
        // Assertion: Check if the luminosity value is present in the array
        assert(luminosities[i] != luminosityToCheck && "Luminosity value is already present in the array");
        printf("Luminosity Value: %f", luminosities[i]);
    }

    // If the function reaches this point, the value is not present in the array
    return 0;
}

// Example of a Runtime Assertion Success
void runtimeAssertionSuccessExample() {
    int size = 3;
    int numbers[3] = {1,2,3};
    int index = 2;
    assert(size > index);
    printf("Number: %d", numbers[index]);
}

// Example of a Runtime Assertion Failure
void runtimeAssertionFailureExample() {
    int size = 3;
    int numbers[3] = {1,2,3};
    int index = 2;
    assert(size > index + 100); // Failure of runtime assertion
    printf("Number: %d", numbers[index]);
}

int main() {
    runtimeAssertionSuccessExample();
    // runtimeAssertionFailureExample();
    printf("Return Value %d", codeViolation());
    printf("Return value: %d", codeOptimization());
}