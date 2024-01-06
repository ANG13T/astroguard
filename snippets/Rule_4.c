/*
 NASA JPL Rule #4: Restric function length to within a single printed page
 No more than 60 lines of code per function

 Tips:
 1. Remove redundancy in code (DRY - Don't Repeat Yourself Principle)
 2. Break down your code into functions and methods
 3. Parameterization (using parameters to make functions more flexible)
 4. Abstraction (abstracting common logic to reuseable components and classes)
 5. Data Structures
 6. Modularization (divide code into modules or files)
 7. Template Patterns and Inheritance

 The following three examples demonstrates methods to fix lengthy code violations:
 1. DRY + Function Break down
 2. Template Patterns and Inheritance + Abstraction
 3. Parameterization + Data Structures
*/

#include <stdio.h>
#include <math.h>

// Violation: Repetitive Code and Anti-discrete Functions
// Sample code calculates the escape velocity of two respective planets
void lengthyCodeViolation1() {
    double gravitational_constant = 6.674 * pow(10, -11);
    double mass_of_celestial_body;
    double radius_of_celestial_body;
    double escape_velocity;

    char[] celestialBody1 = "Earth";
    char[] celestialBody2 = "Mars";

    escape_velocity = sqrt(2 * gravitational_constant * mass_of_celestial_body / radius_of_celestial_body);

    printf("Escape Velocity of %s: %.2f", celestialBody1, escape_velocity);


}

// Fix: DRY Principles and Breaking Down Functions into Auxilary Functions
void optimizedCodeExample1() {

}

// Violation: 
void lengthyCodeViolation2() {

}

// Fix: 
void optimizedCodeExample2() {

}

// Violation: 
void lengthyCodeViolation3() {

}

// Fix: 
void optimizedCodeExample3() {

}

int main() {

}