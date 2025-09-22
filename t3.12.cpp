#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, max, x, y;
    const double EPS = 1e-9;

    printf("Enter sides a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Sides must be positive.\n");
        return 0;
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Triangle does not exist.\n");
        return 0;
    }

    if (a >= b && a >= c) {
        max = a; x = b; y = c;
    } else if (b >= a && b >= c) {
        max = b; x = a; y = c;
    } else {
        max = c; x = a; y = b;
    }

    double left = max * max;
    double right = x * x + y * y;

    if (fabs(left - right) < EPS) {
        printf("Right triangle.\n");
    } else if (left < right) {
        printf("Acute triangle.\n");
    } else {
        printf("Obtuse triangle.\n");
    }

    return 0;
}
