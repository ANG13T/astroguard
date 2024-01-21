/*
 NASA JPL Rule #6: Restrict the scope of data to the smallest possible

 What is a scope?
 A scope is a region where a variable can be defined and utilized.
 
 How to limit scope?
 There are two types of scopes:
 1. Global / File Scopes
 2. Local / Block Scopes

 The general rule of thumb is to limit global scopes as much as possible and utilize local variables.
*/

#include <stdio.h>

// Violation: Uses a global variable (scope is not limited)
// Speed of light in kilometers per second
#define SPEED_OF_LIGHT 299792.458


void ruleViolation() {
    printf("The speed of light in a vacuum is approximately %.3f kilometers per second.\n", SPEED_OF_LIGHT);    
}


// Valid: scoping the variable to the proper function
void ruleAssertion() {
    double LIGHT_SPEED = 299792.458;
    printf("The speed of light in a vacuum is approximately %.3f kilometers per second.\n", LIGHT_SPEED);    
}

int main() {
    ruleViolation();
    ruleAssertion();
}
