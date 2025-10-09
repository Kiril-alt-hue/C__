#pragma once
#include <stdio.h>

typedef struct {
    int numerator;             // numerator
    unsigned int denominator;  // denominator (always positive)
} Rational;

extern unsigned int gcd(unsigned int a, unsigned int b);
extern Rational simplify(Rational r);
extern Rational add(Rational a, Rational b);
extern Rational multiply(Rational a, Rational b);
extern int compare(Rational a, Rational b);
extern void printRational(Rational r);
