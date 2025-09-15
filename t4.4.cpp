#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x, result = 0.0;

    // Read input values
    printf("Enter natural number n: ");
    scanf("%d", &n);

    printf("Enter value of x: ");
    scanf("%lf", &x);


    if (n <= 0) {
        printf("Error: n must be a natural number (n > 0)!\n");
        return 1;
    }

    // Calculate the expression: x + 2x^2 + 3x^3 + ... + nx^n
    printf("\nCalculating: ");
    for (int i = 1; i <= n; i++) {
        double term = i * pow(x, i);
        result += term;

        // Display the current term
        printf("%d*%.2f^%d", i, x, i);
        if (i < n) {
            printf(" + ");
        }
    }

    // Display the result
    printf("\nResult = %.4f\n", result);

    return 0;
}