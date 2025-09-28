#include <stdio.h>

double continued_fraction_c(int n) {
    double result;

    int levels = 2 * n;
    result = (levels % 2 == 0) ? 2.0 : 1.0;


    for (int i = levels - 1; i >= 1; i--) {
        if (i % 2 == 0) {
            result = 2.0 + 1.0 / result;
        } else {
            result = 1.0 + 1.0 / result;
        }
    }
    return result;
}

int main() {
    int n = 2;

    double result_c = continued_fraction_c(n);
    printf("Task 6c:\n");
    printf("x_%d = %f\n\n", 2*n, result_c);

    return 0;
}