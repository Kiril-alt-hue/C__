#include <stdio.h>

int main() {
    double x;
    if (scanf("%lf", &x) != 1) return 0;

    double x2 = x * x;
    double x3 = x2 * x;
    double x4 = x2 * x2;
    double x6 = x3 * x3;
    double x9 = x6 * x3;
    double x12 = x6 * x6;
    double x15 = x12 * x3;
    double x7 = x6 * x;
    double x14 = x7 * x7;
    double x28 = x14 * x14;
    double x8 = x4 * x4;
    double x16 = x8 * x8;
    double x32 = x16 * x16;
    double x64 = x32 * x32;

    printf("x^4 = %g\n", x4);
    printf("x^6 = %g\n", x6);
    printf("x^9 = %g\n", x9);
    printf("x^15 = %g\n", x15);
    printf("x^28 = %g\n", x28);
    printf("x^64 = %g\n", x64);

    return 0;
}
