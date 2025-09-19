#include <stdio.h>
#include <math.h>
#include <float.h>

double sinc(double x) {
    if (isnan(x)) return NAN;
    if (isinf(x)) return 0.0;
    double ax = fabs(x);


    if (ax < 1e-6) {
        double x2 = x * x;
        double x4 = x2 * x2;
        return 1.0 - x2/6.0 + x4/120.0;
    }


    return sin(x) / x;
}

double dsinc(double x) {
    if (isnan(x)) return NAN;
    if (isinf(x)) return 0.0;
    double ax = fabs(x);

    if (ax < 1e-6) {
        double x2 = x * x;
        double x3 = x2 * x;
        return -x/3.0 + x3/30.0;
    }

    double num = x * cos(x) - sin(x);
    double den = x * x;
    return num / den;
}

int main() {
    double vals[] = {0.0, 1e-8, 0.1, M_PI/2.0, M_PI, 10.0};
    int n = sizeof(vals)/sizeof(vals[0]);

    printf(" x\t\tsinc(x)\t\t\tsinc'(x)\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; ++i) {
        double x = vals[i];
        printf("% .8e\t% .12e\t% .12e\n", x, sinc(x), dsinc(x));
    }

    return 0;
}
