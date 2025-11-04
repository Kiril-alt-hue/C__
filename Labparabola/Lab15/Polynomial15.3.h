#pragma once

#include <iostream>
#include <string>

class Polynomial {
private:
    int size;       // Кількість елементів (коефіцієнтів) N. Це також на одиницю більше за найвищий степінь.
    double* coeffs; // Масив дійсних чисел для зберігання коефіцієнтів.

public:
    Polynomial();

    Polynomial(int N);

    Polynomial(const Polynomial& other);

    ~Polynomial();

    void setCoefficients(const double* new_coeffs);

    void setCoefficient(int index, double value);

    void print() const;

    Polynomial& operator=(const Polynomial& other);

    friend std::istream& operator>>(std::istream& is, Polynomial& poly);

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);

    friend std::ofstream& writeToBinaryFile(std::ofstream& ofs, const Polynomial& poly);
};