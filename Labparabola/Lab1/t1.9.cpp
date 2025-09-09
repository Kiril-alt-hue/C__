#include <stdio.h>

int main() {
    double a, b;
    printf("Enter two real numbers: ");
    scanf("%lf %lf", &a, &b);

    double arithmetic = (a + b) / 2.0;
    double harmonic = 2.0 / ((1.0 / a) + (1.0 / b));

    printf("Arithmetic mean: %.6lf\n", arithmetic);
    printf("Harmonic mean: %.6lf\n", harmonic);

    return 0;
}
