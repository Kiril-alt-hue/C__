#include "structures10.1.h"
#include <stdlib.h>

// --------- (a) Date ----------
void inputDate(Date *d) {
    printf("Enter day, month, year: ");
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

void printDate(Date d) {
    printf("Date: %02d.%02d.%d\n", d.day, d.month, d.year);
}

// --------- (b) ChessSquare ----------
void inputSquare(ChessSquare *s) {
    printf("Enter chess square (e.g., a5): ");
    scanf(" %c%d", &s->column, &s->row);
}

void printSquare(ChessSquare s) {
    printf("Square: %c%d\n", s.column, s.row);
}

// --------- (c) Rectangle ----------
void inputRectangle(Rectangle *r) {
    printf("Enter coordinates of vertex 1 (x1 y1): ");
    scanf("%lf %lf", &r->v1.x, &r->v1.y);
    printf("Enter coordinates of opposite vertex 2 (x2 y2): ");
    scanf("%lf %lf", &r->v2.x, &r->v2.y);
}

void printRectangle(Rectangle r) {
    printf("Rectangle vertices: (%.2f, %.2f) and (%.2f, %.2f)\n",
           r.v1.x, r.v1.y, r.v2.x, r.v2.y);
}

// --------- (d) Polynomial ----------
void inputPolynomial(Polynomial *p) {
    printf("Enter polynomial degree: ");
    scanf("%d", &p->degree);

    p->coeff = (double *)malloc((p->degree + 1) * sizeof(double));
    if (!p->coeff) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter %d coefficients (a0 ... a%d): ", p->degree + 1, p->degree);
    for (int i = 0; i <= p->degree; i++)
        scanf("%lf", &p->coeff[i]);
}

void printPolynomial(Polynomial p) {
    printf("Polynomial: ");
    for (int i = p.degree; i >= 0; i--) {
        printf("%.2f", p.coeff[i]);
        if (i > 0) printf("x^%d + ", i);
    }
    printf("\n");
}
