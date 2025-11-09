#include "Rational15.1.h"
#include <cmath>     // Для std::abs
#include <stdexcept> // Для винятків (exceptions)


void Rational::reduce() {
    int common_divisor = std::gcd(std::abs(numerator), denominator);

    numerator /= common_divisor;
    denominator /= common_divisor;

    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

Rational::Rational(int num, int den) {
    if (den == 0) {
        throw std::invalid_argument("Знаменник не може бути нулем.");
    }

    numerator = num;
    denominator = den;

    reduce();
}


void Rational::print() const {
    std::cout << numerator << "/" << denominator;
}

Rational Rational::add(const Rational& other) const {
    int new_denominator = denominator * other.denominator;
    int new_numerator = (numerator * other.denominator) + (other.numerator * denominator);

    return Rational(new_numerator, new_denominator);
}

Rational Rational::subtract(const Rational& other) const {
    int new_denominator = denominator * other.denominator;
    int new_numerator = (numerator * other.denominator) - (other.numerator * denominator);

    return Rational(new_numerator, new_denominator);
}

Rational Rational::multiply(const Rational& other) const {
    int new_numerator = numerator * other.numerator;
    int new_denominator = denominator * other.denominator;

    return Rational(new_numerator, new_denominator);
}

Rational Rational::divide(const Rational& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Ділення на нульовий дріб неможливе.");
    }

    int new_numerator = numerator * other.denominator;
    int new_denominator = denominator * other.numerator;

    return Rational(new_numerator, new_denominator);
}