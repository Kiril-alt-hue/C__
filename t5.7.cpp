#include <stdio.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);


    if (n == 1) {
        printf("S = 0\n");
        return 0;
    }
    if (n == 2) {
        printf("S = 6\n");
        return 0;
    }


    double a_prev = 0, a_curr = 1;
    double b_prev = 0, b_curr = 1;
    double S = 6;
    double p = 4;

    for (int k = 3; k <= n; k++) {
        double b_new = b_curr + a_curr;
        double a_new = a_curr/k + a_prev * b_new;


        a_prev = a_curr;
        a_curr = a_new;
        b_prev = b_curr;
        b_curr = b_new;

        p *= 2;
        S += p / (a_new + b_new);

        printf("k=%d: a=%.4f, b=%.4f, S=%.4f\n", k, a_new, b_new, S);
    }

    printf("S = %.6f\n", S);
    return 0;
}