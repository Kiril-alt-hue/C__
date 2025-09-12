#include <stdio.h>

long long double_factorial(int n) {
    long long result = 1;

    if (n % 2 == 1) { // Odd number: 1 * 3 * 5 * ... * n
        for (int i = 1; i <= n; i += 2) {
            result *= i;
        }
    } else { // Even number: 2 * 4 * 6 * ... * n
        for (int i = 2; i <= n; i += 2) {
            result *= i;
        }
    }

    return result;
}

int main() {
    int n;

    printf("Enter natural number n: ");
    scanf("%d", &n);


    if (n < 0) {
        printf("Error: n must be a natural number (n >= 0)!\n");
        return 1;
    }


    if (n == 0) {
        printf("0!! = 1\n");
        return 0;
    }


    long long result = double_factorial(n);


    printf("%d!! = ", n);

    if (n % 2 == 1) { // Odd number
        for (int i = 1; i <= n; i += 2) {
            printf("%d", i);
            if (i < n - 1) {
                printf(" * ");
            }
        }
    } else { // Even number
        for (int i = 2; i <= n; i += 2) {
            printf("%d", i);
            if (i < n) {
                printf(" * ");
            }
        }
    }

    printf(" = %lld\n", result);

    return 0;
}