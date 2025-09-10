#include <stdio.h>

int main() {
    double a, b;

    printf("Enter the first number: ");
    scanf("%lf", &a);

    printf("Enter the second number: ");
    scanf("%lf", &b);

    printf("Difference: %.3f\n", a - b);
    printf("Product: %.3f\n", a * b);

    return 0;
}
