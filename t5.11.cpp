#include <stdio.h>

int main() {
    int n;
    if (printf("Enter n (non-negative integer): ") < 0) return 1;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (n <= 0) {
        printf("S_%d = %.10f\n", n, 0.0);
        return 0;
    }

    double a_prev = 1.0;    // a_0
    double coeff = 1.0;     // coeff for k=0: 2^0 / 0! = 1
    double sum = 0.0;

    for (int k = 1; k <= n; ++k) {
        coeff *= 2.0 / (double)k;

        double a_curr = (double)k * a_prev + 1.0 / (double)k;

        double term = coeff * a_curr;
        sum += term;

        a_prev = a_curr;
    }

    printf("S_%d = %.10f\n", n, sum);
    return 0;
}
