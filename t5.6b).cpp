#include <stdio.h>

double continued_fraction_b(int n) {
    double b_k = 4 * n + 2;


    for (int k = 1; k <= n; k++) {
        b_k = 4 * (n - k) + 2 + 1.0 / b_k;
    }

    return 2.0 + 1.0 / b_k;
}

int main() {
    int n = 3;

    double result_b = continued_fraction_b(n);
    printf("Task 6b:\n");
    printf("lambda_%d = %f\n\n", n, result_b);

    return 0;
}