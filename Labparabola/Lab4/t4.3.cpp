#include <stdio.h>
#include <math.h>


double polynomial_a(int n, double x) {
    double result = 0;
    for (int i = 0; i <= n; i++) {
        result += pow(x, i);
    }
    return result;
}


double polynomial_b(int n, double x, double y) {
    double result = 0;
    for (int i = 0; i <= n; i++) {
        int exponent = (i == 0) ? 0 : pow(2, i);
        double term = pow(x, exponent) * pow(y, i);
        result += term;
    }
    return result;
}

int main() {
    // Part a: y = x^n + x^(n-1) + ... + x^2 + x + 1, n = 3, x = 2
    int n_a = 3;
    double x_a = 2.0;
    double result_a = polynomial_a(n_a, x_a);

    printf("Part a: y = x^n + x^(n-1) + ... + x^2 + x + 1\n");
    printf("n = %d, x = %.1f\n", n_a, x_a);
    printf("Result: y = %.2f\n\n", result_a);


    // Part b: y = x^(2^n)*y^n + x^(2^(n-1))*y^(n-1) + ... + x^2*y + 1, n = 4, x = 1, y = 2
    int n_b = 4;
    double x_b = 1.0;
    double y_b = 2.0;
    double result_b = polynomial_b(n_b, x_b, y_b);

    printf("Part b: y = x^(2^n)*y^n + x^(2^(n-1))*y^(n-1) + ... + x^2*y + 1\n");
    printf("n = %d, x = %.1f, y = %.1f\n", n_b, x_b, y_b);
    printf("Result: y = %.2f\n\n", result_b);

    return 0;
}