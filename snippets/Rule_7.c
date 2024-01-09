/*
 NASA JPL Rule #7: Check the return value of all non-void functions, or cast to void to indicate the return value is useless
*/

#include <stdio.h>

// returns the doppler shift of a body given its velocity (its often used in astronomy to find out the wavelength emission of stars relative to an observer ie. blueshift = moving closer and redshift = moving farther)
double calculateDopplerShift(double velocity, double wavelength) {
    double LIGHT_SPEED = 299792.458;
    return (velocity / LIGHT_SPEED) * wavelength;
}

void example() {
    double velocity = 10000.0;
    double wavelength = 5.0e-7;  // 500 nanometers (visible light)

    // Example 1: Adheres to Best Practice (Casting)
    double doppler = calculateDopplerShift(velocity, wavelength);

    printf("Doppler Shift: %.4e meters\n", doppler);

    // Example 2: Ignoring the return value and casting to void
    (void) calculateDopplerShift(0,0);

    // Example 3: Violation of Coding Standard (not checking nor casting)
    calculateDopplerShift(0,0);
}

int main() {
    example();
}