#include <stdio.h>
#include <math.h>


double taylor_exp(double x, double eps) {
    double term = 1.0;
    double sum = 1.0;
    int n = 1;

    while (fabs(term) > eps) {
        term *= x / n;
        sum += term;
        n++;
    }
    return sum;
}

double taylor_phi(double x, double eps) {
    double term = x;      // first term
    double sum = x;
    int k = 1;

    while (fabs(term) > eps) {
        term *= (-1.0) * x * x / ( (2*k+1) * k );
        sum += term;
        k++;
    }
    return sum;
}

int main() {
    double x, eps;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter precision eps: ");
    scanf("%lf", &eps);

    // (a) e^x
    double series_exp = taylor_exp(x, eps);
    double math_exp = exp(x);

    printf("\n(a) e^x:\n");
    printf("Taylor series result = %.10f\n", series_exp);
    printf("math.h exp(x)       = %.10f\n", math_exp);
    printf("Difference          = %.10e\n", fabs(series_exp - math_exp));

    // (b) Phi(x)
    double series_phi = taylor_phi(x, eps);
    double math_phi = 0.5 * sqrt(M_PI) * erf(x);

    printf("\n(b) Phi(x):\n");
    printf("Taylor series result = %.10f\n", series_phi);
    printf("math.h erf(x) result = %.10f\n", math_phi);
    printf("Difference           = %.10e\n", fabs(series_phi - math_phi));

    return 0;
}
