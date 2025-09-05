#include <stdio.h>
#include <math.h>

double f2(double x) {
    double y = (pow(x, 5) - 1)/(x - 1);
    return y;
}

int main() {
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    printf("y = %.2lf\n", f2(x));
}