#include <stdio.h>

int main() {
    int n;
    double derangement = 0.0;
    double term = 1.0;

    printf("Enter a natural number n < 25: ");
    scanf("%d", &n);

    derangement = 1.0;

    for (int i = 1; i <= n; i++) {
        term = term * (-1.0) / i;
        derangement += term;
    }

    term = 1.0;
    double result = 0.0;

    double series_term;
    int sign = 1;

    for (int k = 0; k <= n; k++) {
        series_term = 1.0;
        for (int j = k + 1; j <= n; j++) {
            series_term *= j;
        }

        result += sign * series_term;
        sign = -sign;
    }

    printf("The subfactorial !%d is: %.0f\n", n, result);
    return 0;
}