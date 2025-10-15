#include <stdio.h>
#include <stdlib.h>
#include "polynomal11.5.h"

void printPolynomial(const Polynomial* p) {
    if (!p || p->m == 0) {
        printf("0\n");
        return;
    }

    for (int i = 0; i < p->m; ++i) {
        Monomial mono = p->monomials[i];

        if (i > 0) {
            if (mono.coef < 0) {
                printf(" - ");
            } else {
                printf(" + ");
            }
        } else if (mono.coef < 0) {
            printf("-");
        }

        double c = (mono.coef > 0) ? mono.coef : -mono.coef;

        if (c != 1.0 || mono.deg == 0) {
            printf("%.1f", c);
        }

        if (mono.deg > 0) {
            printf("x");
            if (mono.deg > 1) {
                printf("^%d", mono.deg);
            }
        }
    }
    printf("\n");
}


void addPolynomialToFile(const char* filename) {
    FILE* file = fopen(filename, "ab");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    int m;
    printf("Enter the number of monomials (non-zero terms): ");
    scanf("%d", &m);
    if (m <= 0) {
        printf("The number of monomials must be positive.\n");
        fclose(file);
        return;
    }

    fwrite(&m, sizeof(int), 1, file);

    printf("Enter %d monomials in the format (coefficient degree):\n", m);
    for (int i = 0; i < m; ++i) {
        Monomial mono;
        printf("Monomial %d: ", i + 1);
        scanf("%lf %d", &mono.coef, &mono.deg);
        fwrite(&mono, sizeof(Monomial), 1, file);
    }

    fclose(file);
    printf("Polynomial successfully added to file %s\n", filename);
}

void printPolynomialFromFile(const char* filename, int polyIndex) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }

    int currentPoly = 0;
    while (!feof(file)) {
        int m;
        if (fread(&m, sizeof(int), 1, file) != 1) {
            break;
        }
        currentPoly++;

        if (currentPoly == polyIndex) {
            Polynomial p;
            p.m = m;
            p.monomials = (Monomial*)malloc(m * sizeof(Monomial));
            if (!p.monomials) {
                fprintf(stderr, "Memory allocation error\n");
                fclose(file);
                return;
            }

            fread(p.monomials, sizeof(Monomial), m, file);
            printf("Polynomial #%d: ", polyIndex);
            printPolynomial(&p);

            free(p.monomials);
            fclose(file);
            return;
        } else {
            fseek(file, m * sizeof(Monomial), SEEK_CUR);
        }
    }

    printf("Polynomial with index %d not found.\n", polyIndex);
    fclose(file);
}

void calculateAndPrintDerivative(const char* filename, int polyIndex) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    int currentPoly = 0;
    while (!feof(file)) {
        int m;
        if (fread(&m, sizeof(int), 1, file) != 1) break;
        currentPoly++;

        if (currentPoly == polyIndex) {
            Monomial* monomials = (Monomial*)malloc(m * sizeof(Monomial));
            fread(monomials, sizeof(Monomial), m, file);

            Polynomial derivative;
            derivative.m = 0;
            derivative.monomials = (Monomial*)malloc(m * sizeof(Monomial));

            for (int i = 0; i < m; ++i) {
                if (monomials[i].deg > 0) {
                    derivative.monomials[derivative.m].coef = monomials[i].coef * monomials[i].deg;
                    derivative.monomials[derivative.m].deg = monomials[i].deg - 1;
                    derivative.m++;
                }
            }

            printf("Derivative of polynomial #%d: ", polyIndex);
            printPolynomial(&derivative);

            free(monomials);
            free(derivative.monomials);
            fclose(file);
            return;
        } else {
            fseek(file, m * sizeof(Monomial), SEEK_CUR);
        }
    }

    printf("Polynomial with index %d not found.\n", polyIndex);
    fclose(file);
}

void deletePolynomialFromFile(const char* filename, int polyIndex) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open source file");
        return;
    }

    const char* tempFilename = "temp.dat";
    FILE* tempFile = fopen(tempFilename, "wb");
    if (!tempFile) {
        perror("Failed to create temporary file");
        fclose(file);
        return;
    }

    int currentPoly = 0;
    int found = 0;
    while (!feof(file)) {
        int m;
        if (fread(&m, sizeof(int), 1, file) != 1) break;
        currentPoly++;

        Monomial* monomials = (Monomial*)malloc(m * sizeof(Monomial));
        fread(monomials, sizeof(Monomial), m, file);

        if (currentPoly != polyIndex) {
            // Copy all other polynomials to the temporary file
            fwrite(&m, sizeof(int), 1, tempFile);
            fwrite(monomials, sizeof(Monomial), m, tempFile);
        } else {
            found = 1; // Mark that the polynomial to be deleted was found
        }
        free(monomials);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(filename);
        rename(tempFilename, filename);
        printf("Polynomial #%d successfully deleted.\n", polyIndex);
    } else {
        remove(tempFilename);
        printf("Polynomial with index %d not found.\n", polyIndex);
    }
}

void replaceCoefficient(const char* filename, int polyIndex, int deg, double newCoef) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open source file");
        return;
    }

    const char* tempFilename = "temp.dat";
    FILE* tempFile = fopen(tempFilename, "wb");
    if (!tempFile) {
        perror("Failed to create temporary file");
        fclose(file);
        return;
    }

    int currentPoly = 0;
    int foundPoly = 0;
    int coefChanged = 0;
    while (!feof(file)) {
        int m;
        if (fread(&m, sizeof(int), 1, file) != 1) break;
        currentPoly++;

        Monomial* monomials = (Monomial*)malloc(m * sizeof(Monomial));
        fread(monomials, sizeof(Monomial), m, file);

        if (currentPoly == polyIndex) {
            foundPoly = 1;
            for (int i = 0; i < m; ++i) {
                if (monomials[i].deg == deg) {
                    monomials[i].coef = newCoef;
                    coefChanged = 1;
                    break;
                }
            }
        }

        fwrite(&m, sizeof(int), 1, tempFile);
        fwrite(monomials, sizeof(Monomial), m, tempFile);
        free(monomials);
    }

    fclose(file);
    fclose(tempFile);

    if (foundPoly) {
        remove(filename);
        rename(tempFilename, filename);
        if (coefChanged) {
            printf("Coefficient for degree %d in polynomial #%d was changed to %.1f.\n", deg, polyIndex, newCoef);
        } else {
            printf("Warning: Term with degree %d not found in polynomial #%d. File was not changed.\n", polyIndex, deg);
        }
    } else {
        remove(tempFilename);
        printf("Polynomial with index %d not found.\n", polyIndex);
    }
}