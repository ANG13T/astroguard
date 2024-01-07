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

    // Values for Earth
    char celestialBody1[] = "Earth";
    double mass_of_celestial_body = 5.97 * pow(10, 24);
    double radius_of_celestial_body = 6.37 * pow(10, 6);
    double escape_velocity;

    // Values for Jupiter
    char celestialBody2[] = "Jupiter";
    double mass_of_celestial_body_2 = 1.89 * pow(10, 27);
    double radius_of_celestial_body_2 = 6.99 * pow(10, 7);
    double escape_velocity_2;

    escape_velocity = sqrt(2 * gravitational_constant * mass_of_celestial_body / radius_of_celestial_body);

    printf("Escape Velocity of %s: %.2f (m/s) \n", celestialBody1, escape_velocity);

    escape_velocity_2 = sqrt(2 * gravitational_constant * mass_of_celestial_body_2 / radius_of_celestial_body_2);

    printf("Escape Velocity of %s: %.2f (m/s) \n", celestialBody2, escape_velocity_2);
}

// Fix: DRY Principles and Breaking Down Functions into Auxilary Functions (3 Discrete Functions)
double calculateEscapeVelocity(double mass, double radius) {
    double gravitational_constant = 6.674 * pow(10, -11);
    return sqrt(2 * gravitational_constant * mass / radius);
}

void printEscapeVelocity(char name[], double escapeVelocity) {
    printf("Escape Velocity of %s: %.2f (m/s) \n", name, escapeVelocity);
}

void optimizedCodeExample1() {
    // Values for Earth
    char celestialBody1[] = "Earth";
    double mass_of_celestial_body = 5.97 * pow(10, 24);
    double radius_of_celestial_body = 6.37 * pow(10, 6);
    double escape_velocity = calculateEscapeVelocity(mass_of_celestial_body, radius_of_celestial_body);
    printEscapeVelocity(celestialBody1, escape_velocity);

    // Values for Jupiter
    char celestialBody2[] = "Jupiter";
    double mass_of_celestial_body_2 = 1.89 * pow(10, 27);
    double radius_of_celestial_body_2 = 6.99 * pow(10, 7);
    double escape_velocity_2 = calculateEscapeVelocity(mass_of_celestial_body_2, radius_of_celestial_body_2);
    printEscapeVelocity(celestialBody2, escape_velocity_2);
}

// Violation: Does not use Inheritance or Abstraction causing Code Redundancy
// Sample code calculates the Blackbody radiation power via Stefan-Boltzmann law
void lengthyCodeViolation2() {
    const double sigma = 5.67e-8;  // Stefan-Boltzmann constant

    // Values for the Sun
    double temperature_star1 = 5778;
    double radius_star1 = 6.96e8;
    double radiation_star1 = sigma * 4 * M_PI * pow(radius_star1, 2) * pow(temperature_star1, 4);
    printf("Radiation for the Sun (Temperature = %.2f K): %.4e W/m^2\n", temperature_star1, radiation_star1);

    // Values for Vega
    double temperature_star2 = 9600;
    double radius_star2 = 2.36e8;
    double radiation_star2 = sigma * 4 * M_PI * pow(radius_star2, 2) * pow(temperature_star2, 4);
    printf("Radiation for Vega (Temperature = %.2f K): %.4e W/m^2\n", temperature_star1, radiation_star1);
}

// Fix: Create a class and implement abstract methods

// Abstract class for stars
struct Star {
    double (*calculateSurfaceTemperature)(struct Star*);
    double (*calculateRadius)(struct Star*);
    double (*calculateRadiation)(struct Star*);

    double temperature;
    double radius;
};

// Function to calculate surface temperature for a star
double calculateSurfaceTemperature_Star(struct Star* star) {
    return star->temperature;
}

// Function to calculate radius for a star
double calculateRadius_Star(struct Star* star) {
    return star->radius;
}

// Function to calculate radiation for a star
double calculateRadiation_Star(struct Star* star) {
    const double sigma = 5.67e-8;  // Stefan-Boltzmann constant
    return 4 * M_PI * pow(star->radius, 2) * sigma * pow(star->temperature, 4);
}

void optimizedCodeExample2() {
    struct Star vega = {
        radius: 36e8,
        temperature: 9600
    };

    struct Star sun = {
        radius: 96e8,
        temperature: 5778
    };

    printf("Radiation for the Sun (Temperature = %.2f K, Radius = %.2e m): %.4e W\n", sun.calculateSurfaceTemperature(&sun), sun.calculateRadius(&sun), sun.calculateRadiation(&sun));
    printf("Radiation for Vega (Temperature = %.2f K, Radius = %.2e m): %.4e W\n", vega.calculateSurfaceTemperature(&vega), vega.calculateRadius(&vega), vega.calculateRadiation(&vega));
}

// Violation: does not utilize data structures making the code redundant and no parameterization
// simple program to sum values
void lengthyCodeViolation3() {
    int num1, num2, num3;

    int sum = num1 + num2 + num3;

    printf("Sum %d\n", sum);
}

// Fix: use a data structure (array) and include a function with parametrization

int calcSum(int nums[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += nums[i];
    }

    return sum;
}

void optimizedCodeExample3() {
    int numbers[] = {10, 20, 30, 40, 50};
    int sum = calcSum(numbers, 5);
    printf("Sum: %d\n", sum);
}

int main() {
    lengthyCodeViolation1();
    optimizedCodeExample1();

    lengthyCodeViolation2();
    optimizedCodeExample2();

    lengthyCodeViolation3();
    optimizedCodeExample3();
}