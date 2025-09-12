#include <stdio.h>

int main() {
    int n;
    double x;
    double sum = 1.0;
    double term = 1.0;

    printf("Enter real number |x| < 1: ");
    scanf("%lf", &x);
    printf("Enter integer n >= 0: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        term *= x / i;
        sum += term;
    }

    printf("The sum of the series is: %.15f\n", sum);
    return 0;
}