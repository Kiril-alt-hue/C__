#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Enter the a: ");
    scanf("%lf", &a);
    printf("Enter the b: ");
    scanf("%lf", &b);

    c = hypot(a, b);
    printf("Hypot(%.2f, %.2f) = %.2f\n", a, b, c);

    return 0;
}