#pragma once

#include <iostream>
#include <numeric> // Для std::gcd (з C++17)

class Rational {
private:
    int numerator;   // Чисельник
    int denominator; // Знаменник (натуральне число)
    void reduce();

public:

    Rational() : numerator(0), denominator(1) {}

    Rational(int num, int den);

    void print() const;

    Rational add(const Rational& other) const;

    Rational subtract(const Rational& other) const;

    Rational multiply(const Rational& other) const;

    Rational divide(const Rational& other) const;
};