#ifndef POLYNOMAL11_5_H
#define POLYNOMAL11_5_H

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct {
    double coef; // The coefficient
    int deg;     // The degree
} Monomial;


typedef struct {
    int m;              // Number of monomials
    Monomial* monomials; // Dynamic array of monomials
} Polynomial;


void addPolynomialToFile(const char* filename);

void printPolynomialFromFile(const char* filename, int polyIndex);

void calculateAndPrintDerivative(const char* filename, int polyIndex);

void deletePolynomialFromFile(const char* filename, int polyIndex);

void replaceCoefficient(const char* filename, int polyIndex, int deg, double newCoef);

#endif // POLYNOMIAL_H
#endif //POLYNOMAL11_5_H
