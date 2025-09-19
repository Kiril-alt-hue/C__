#include <stdio.h>

double calculate_polynomial(double x) {

    double result = 1.0;
    result = result * x + 5.0;
    result = result * x + 10.0;
    result = result * x + 10.0;
    result = result * x + 5.0;
    result = result * x + 1.0;

    return result;
}

int main() {
    double x;

    printf("Enter x: ");
    scanf("%lf", &x);

    double y = calculate_polynomial(x);
    printf("y = x^5 + 5x^4 + 10x^3 + 10x^2 + 5x + 1 for x = %.2f: %.2f\n", x, y);

    return 0;
}