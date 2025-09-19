#include <stdio.h>

int main() {
    int n;
    long long factorial = 1;

    printf("Enter a natural number n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: n must be a natural number!\n");
        return 1;
    }

    printf("\nLoop with increasing range:\n");
    printf("%d! = ", n);

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        printf("%d", i);
        if (i < n) {
            printf("*");
        }
    }
    printf(" = %lld\n", factorial);

    factorial = 1;

    printf("\nLoop with decreasing range:\n");
    printf("%d! = ", n);

    for (int i = n; i >= 1; i--) {
        factorial *= i;
        printf("%d", i);
        if (i > 1) {
            printf("*");
        }
    }
    printf(" = %lld\n", factorial);

    return 0;
}