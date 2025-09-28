#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}


double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// a)
double product_a(int n) {
    double P = 1.0;
    double term;

    for (int i = 1; i <= n; i++) {
        term = 1.0 + 1.0 / factorial(i);
        P *= term;
        printf("i = %d: term = %.6f, P = %.10f\n", i, term, P);
    }

    return P;
}

// б)
double product_b(int n) {
    double P = 1.0;
    double term;
    int sign; // знак: +1 або -1

    for (int i = 1; i <= n; i++) {
        // Обчислюємо знак: (-1)^(i+1)
        sign = (i % 2 == 1) ? 1 : -1;

        // Обчислюємо член добутку
        term = 1.0 + sign * (i * i) / power(2, i);
        P *= term;

        printf("i = %d: sign = %d, term = %.6f, P = %.10f\n", i, sign, term, P);
    }
}
int main() {
    int n;

    printf("a):");
    printf(" n = ");
    scanf("%d", &n);
    double result_a = product_a(n);
    printf("\na): P_%d = %.10f\n\n", n, result_a);

    printf("b):");
    printf(" n = ");
    scanf("%d", &n);
    double result_b = product_b(n);
    printf("\nb): P_%d = %.10f\n", n, result_b);

    return 0;
}