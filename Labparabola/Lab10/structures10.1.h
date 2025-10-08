#pragma once
#include <stdio.h>

// ---------- (a) Date ----------
typedef struct {
    int day;
    int month;
    int year;
} Date;

// ---------- (b) Chess Square ----------
typedef struct {
    char column;  // from 'a' to 'h'
    int row;      // from 1 to 8
} ChessSquare;

// ---------- (c) Rectangle ----------
typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point v1;
    Point v2;
} Rectangle;

// ---------- (d) Polynomial ----------
typedef struct {
    int degree;      // polynomial degree
    double *coeff;   // coefficients (a0 ... an)
} Polynomial;

// ---------- Function declarations ----------
extern void inputDate(Date *d);
extern void printDate(Date d);

extern void inputSquare(ChessSquare *s);
extern void printSquare(ChessSquare s);

extern void inputRectangle(Rectangle *r);
extern void printRectangle(Rectangle r);

extern void inputPolynomial(Polynomial *p);
extern void printPolynomial(Polynomial p);
