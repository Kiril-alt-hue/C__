#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

int main() {
    double x, epsilon;
    const int MAX_ITER = 1000000;

    printf("Enter x: ");
    if (scanf("%lf", &x) != 1) return 1;

    printf("Enter epsilon (accuracy > 0): ");
    if (scanf("%lf", &epsilon) != 1 || epsilon <= 0.0) return 1;

    double term = 1.0;   // t0 = 1
    double sum = 1.0;    // initial sum includes t0
    int k = 1;
    bool stopped_by_epsilon = false;

    while (k < MAX_ITER) {
        // compute next term: t_k = t_{k-1} * x / k
        term *= x / (double)k;

        if (!isfinite(term)) {
            fprintf(stderr, "Term became non-finite at k=%d. Aborting.\n", k);
            break;
        }

        sum += term;

        if (fabs(term) < epsilon) {
            stopped_by_epsilon = true;
            ++k;
            break;
        }

        ++k;
    }

    printf("Approximation: e^%.2f ~ %.10e\n", x, sum);

    if (stopped_by_epsilon) {
        printf("Stopped because last term |t_k| < epsilon at k=%d, last term = %.10e\n", k-1, term);
    } else if (!isfinite(term)) {
        printf("Stopped due to non-finite term at k=%d\n", k);
    } else {
        printf("Stopped due to reaching MAX_ITER (%d). Last term = %.10e\n", MAX_ITER, term);
    }

    return 0;
}
