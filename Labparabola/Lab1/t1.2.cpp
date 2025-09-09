#include <stdio.h>
#include <math.h>

int main() {
    float f = 1e-4f;
    double d1 = 24.33E5;
    double d2 = M_PI;
    double d3 = M_E;
    double d4 = sqrt(5);
    double d5 = log(100);
    long double ld = 1234567.89123L;

    printf("float f = %.2f\n", f);
    printf("double d1 = %.2f\n", d1);
    printf("pi = %.2f\n", d2);
    printf("e = %.2f\n", d3);
    printf("sqrt(5) = %.2f\n", d4);
    printf("ln(100) = %.2f\n", d5);
    printf("long double ld = %.2Lf\n", ld);

    return 0;
}
