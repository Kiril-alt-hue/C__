#include <stdio.h>

double continued_fraction_a(int n, double b) {
    double result = b;
    for (int i = 1; i < n; i++) {
        result = b + 1.0 / result;
    }
    return result;
}

int main() {
    int n = 5;
    double b_value = 2.0;

    double result_a = continued_fraction_a(n, b_value);
    printf("Task 6a:\n");
    printf("b_%d (with b=%.1f) = %f\n\n", n, b_value, result_a);

    return 0;
}