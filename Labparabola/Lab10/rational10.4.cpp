#include "rational10.4.h"

// Function to find the greatest common divisor (GCD)
unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Simplify (reduce) a rational number
Rational simplify(Rational r) {
    unsigned int d = gcd((r.numerator < 0 ? -r.numerator : r.numerator), r.denominator);
    r.numerator /= d;
    r.denominator /= d;
    return r;
}

// Add two rational numbers
Rational add(Rational a, Rational b) {
    Rational result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return simplify(result);
}

// Multiply two rational numbers
Rational multiply(Rational a, Rational b) {
    Rational result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return simplify(result);
}

// Compare two rational numbers
int compare(Rational a, Rational b) {
    int left = a.numerator * b.denominator;
    int right = b.numerator * a.denominator;

    if (left == right) return 0;
    else if (left > right) return 1;
    else return -1;
}

// Print rational number
void printRational(Rational r) {
    printf("%d/%u\n", r.numerator, r.denominator);
}
