#include <stdio.h>

double chebyshev_value(int n, double x) {
    if (n == 0) return 1.0;
    if (n == 1) return x;

    double Tnm2 = 1.0; // T0
    double Tnm1 = x;   // T1
    double Tn;

    for (int k = 2; k <= n; k++) {
        Tn = 2.0 * x * Tnm1 - Tnm2;
        Tnm2 = Tnm1;
        Tnm1 = Tn;
    }
    return Tn;
}


void chebyshev_coeffs(int n) {
    double prev[256] = {0}, curr[256] = {0}, next[256] = {0};

    prev[0] = 1.0;

    if (n == 0) {
        printf("T0(x) = 1\n");
        return;
    }

    curr[1] = 1.0;

    if (n == 1) {
        printf("T1(x) = x\n");
        return;
    }


    for (int k = 2; k <= n; k++) {
        for (int i = 0; i <= n; i++) next[i] = 0.0;

        for (int i = 0; i < k; i++) {
            next[i+1] += 2.0 * curr[i];
        }

        for (int i = 0; i <= k-2; i++) {
            next[i] -= prev[i];
        }

        for (int i = 0; i <= k; i++) {
            prev[i] = curr[i];
            curr[i] = next[i];
        }
    }


    printf("Coefficients of T%d(x):\n", n);
    for (int i = 0; i <= n; i++) {
        if (curr[i] != 0.0) {
            printf("  x^%d: %.0f\n", i, curr[i]);
        }
    }
}

int main() {
    int n;
    double x;

    printf("Enter n (<256): ");
    scanf("%d", &n);
    printf("Enter x: ");
    scanf("%lf", &x);

    double val = chebyshev_value(n, x);
    printf("T_%d(%.3f) = %.6f\n", n, x, val);

    chebyshev_coeffs(n);

    return 0;
}
