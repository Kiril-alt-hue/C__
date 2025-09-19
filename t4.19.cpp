#include <stdio.h>

int main() {
    int n;
    double p = 1.0;

    printf("Enter integer n (n > 2): ");
    if (scanf("%d", &n) != 1 || n <= 2) {
        printf("Invalid n. Must be integer > 2.\n");
        return 1;
    }

    for (int k = 2; k <= n; ++k) {
        double term = 1.0 - 1.0 / ( (double)k * (double)k );
        p *= term;
    }

    printf("Product p for n = %d is %.12g\n", n, p);

    return 0;
}
