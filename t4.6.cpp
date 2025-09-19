#include <stdio.h>
#include <math.h>


double nested_sqrt_a(int n) {
    double result = 0.0;

    for (int i = n; i >= 1; i--) {
        if (i == n) {
            result = sqrt(2.0);  // Innermost: sqrt(2)
        } else {
            result = sqrt(2.0 + result);
        }
    }

    return result;
}


double nested_sqrt_b(int n) {
    double result = 0.0;


    for (int i = n; i >= 1; i--) {
        if (i == n) {
            result = sqrt(3.0 * i);  // Innermost: sqrt(3n)
        } else {
            result = sqrt(3.0 * i + result);
        }
    }

    return result;
}

int main() {
    int n;
    printf("Enter natural number n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: n must be a natural number (n > 0)!\n");
        return 1;
    }

    printf("\nPart a: sqrt(2 + sqrt(2 + ... + sqrt(2))) (%d square roots)\n", n);
    double result_a = nested_sqrt_a(n);
    printf("Result = %.6f\n", result_a);

    printf("Calculation steps:\n");
    double current = 0.0;
    for (int i = n; i >= 1; i--) {
        if (i == n) {
            current = sqrt(2.0);
            printf("Step %d: sqrt(2) = %.6f\n", n - i + 1, current);
        } else {
            current = sqrt(2.0 + current);
            printf("Step %d: sqrt(2 + %.6f) = %.6f\n", n - i + 1, current, sqrt(2.0 + current));
        }
    }

    printf("\nPart b: sqrt(3 + sqrt(6 + ... + sqrt(3(n-1) + sqrt(3n))))\n");
    double result_b = nested_sqrt_b(n);
    printf("Result = %.6f\n", result_b);


    printf("Calculation steps:\n");
    current = 0.0;
    for (int i = n; i >= 1; i--) {
        if (i == n) {
            current = sqrt(3.0 * i);
            printf("Step %d: sqrt(%.0f) = %.6f\n", n - i + 1, 3.0 * i, current);
        } else {
            current = sqrt(3.0 * i + current);
            printf("Step %d: sqrt(%.0f + %.6f) = %.6f\n", n - i + 1, 3.0 * i, current, sqrt(3.0 * i + current));
        }
    }

    return 0;
}