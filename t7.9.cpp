#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid n\n");
        return 1;
    }

    double a, max;
    for (int i = 1; i <= n; i++) {
        printf("Enter a%d: ", i);
        if (scanf("%lf", &a) != 1) {
            printf("Invalid input\n");
            return 1;
        }


        double val = (i % 2 == 0) ? a : -a;

        if (i == 1) {
            max = val;
        } else {
            if (val > max) max = val;
        }
    }

    printf("Result: max = %.6f\n", max);
    return 0;
}
