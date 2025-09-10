#include <stdio.h>
#include <math.h>

double arctg(double x) {
    return atan(x);
}

double arctg_derivative(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    double x;

    printf("Enter x value: ");
    scanf("%lf", &x);

    double result = arctg(x);
    double derivative = arctg_derivative(x);

    printf("\nResults:\n");
    printf("arctg(%.2f) = %.6f radians\n", x, result);
    printf("arctg(%.2f) = %.6f degrees\n", x, result * 180.0 / M_PI);
    printf("Derivative at x = %.2f: %.6f\n", x, derivative);

    printf("\nComparison with standard library:\n");
    printf("Our arctg(%.2f): %.6f\n", x, result);
    printf("Standard atan(%.2f): %.6f\n", x, atan(x));

    return 0;
}