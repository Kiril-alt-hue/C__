#include "Rational15.1.h"
#include <iostream>
#include <cmath>
#include <iomanip> // For setprecision

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Target accuracy (epsilon) for series calculation
const double SERIES_EPSILON = 0.01;
// The value the series should converge to: Pi^2 / 12
const double SERIES_TARGET_VALUE = (M_PI * M_PI) / 12.0;

void testRationalClass() {
    std::cout << "=================================================" << std::endl;
    std::cout << "Class 'Rational Number'" << std::endl;
    std::cout << "=================================================" << std::endl;

    try {
        Rational r1(1, 2);   // Creates 1/2
        Rational r2(3, 4);   // Creates 3/4
        Rational r3(4, -8);  // Creates -4/8, which should reduce to -1/2
        Rational r4(-10, 15); // Creates -10/15, which should reduce to -2/3

        std::cout << "--- Testing Initialization and Reduction ---" << std::endl;
        std::cout << "r1: ";
        r1.print();
        std::cout << std::endl;

        std::cout << "r2: ";
        r2.print();
        std::cout << std::endl;

        std::cout << "r3 (4/-8, reduced): ";
        r3.print();
        std::cout << std::endl;

        std::cout << "r4 (-10/15, reduced): ";
        r4.print();
        std::cout << std::endl;

        std::cout << "\n--- Testing Arithmetic Operations (r1 = 1/2, r2 = 3/4) ---" << std::endl;

        // Addition
        Rational sum = r1.add(r2); // 1/2 + 3/4 = 5/4
        std::cout << "Sum (r1 + r2 = 1/2 + 3/4): ";
        sum.print(); // Outputs: 5/4
        std::cout << std::endl;

        // Subtraction
        Rational diff = r2.subtract(r1); // 3/4 - 1/2 = 1/4
        std::cout << "Difference (r2 - r1 = 3/4 - 1/2): ";
        diff.print(); // Outputs: 1/4
        std::cout << std::endl;

        // Multiplication
        Rational product = r1.multiply(r2); // 1/2 * 3/4 = 3/8
        std::cout << "Product (r1 * r2 = 1/2 * 3/4): ";
        product.print(); // Outputs: 3/8
        std::cout << std::endl;

        // Division
        Rational quotient = r1.divide(r2); // 1/2 / 3/4 = 2/3
        std::cout << "Quotient (r1 / r2 = 1/2 / 3/4): ";
        quotient.print(); // Outputs: 2/3
        std::cout << std::endl;

        std::cout << "\n--- Testing Errors ---" << std::endl;
        // Comments on tests that throw exceptions (inactive)
        // Rational zero(0, 5); // Zero fraction
        // r1.divide(zero); // Attempt to divide by zero (will throw exception)

        // Rational bad_rational(1, 0); // Attempt to create with zero denominator (will throw exception)

    } catch (const std::invalid_argument& e) {
        // Exception handling (e.g., division by zero)
        std::cerr << "Rational Class Error: " << e.what() << std::endl;
    }
}

void calculateSeriesSum() {
    std::cout << "\n\n=================================================" << std::endl;
    std::cout << "Series Sum Calculation (Pi^2 / 12)" << std::endl;
    std::cout << "=================================================" << std::endl;

    double sum = 0.0;     // Current sum of the series
    double term = 0.0;    // Current term of the series
    int n = 1;            // Index of the series term (n)

    std::cout << "Target Accuracy (Epsilon): " << SERIES_EPSILON << std::endl;

    do {
        // Determine the sign: +1 if n is odd; -1 if n is even
        double sign = (n % 2 == 1) ? 1.0 : -1.0;
        // Calculate the term: sign * (1.0 / n^2)
        term = sign * (1.0 / (double)n / n);

        // Check the stop condition: |a_n| < EPSILON
        if (std::abs(term) < SERIES_EPSILON) {
            break;
        }

        sum += term;
        n++;
    } while (true);

    std::cout << "\n--- Calculation Results ---" << std::endl;
    std::cout << "Number of Terms Calculated (N): " << n - 1 << std::endl;
    std::cout << "Calculated Series Sum (S_N): " << std::fixed << std::setprecision(4) << sum << std::endl;

    double difference = std::abs(sum - SERIES_TARGET_VALUE);

    std::cout << "\n--- Convergence Check ---" << std::endl;
    std::cout << "Reference Value Pi^2 / 12: " << std::fixed << std::setprecision(4) << SERIES_TARGET_VALUE << std::endl;
    std::cout << "Difference |S_N - Target|: " << std::fixed << std::setprecision(6) << difference << std::endl;

    if (difference < SERIES_EPSILON) {
        std::cout << "CONCLUSION: The series converges to Pi^2 / 12 with accuracy " << SERIES_EPSILON << "." << std::endl;
    } else {
        std::cout << "CONCLUSION: The difference is greater than or equal to the specified accuracy." << std::endl;
    }
}


int main() {

    testRationalClass();
    calculateSeriesSum();

    return 0;
}