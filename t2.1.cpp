#include <stdio.h>
#include <math.h>

// int main() {
//     double x;
//     double res;
//     printf("Enter x: ");
//     scanf("%lf", &x);
//
//     res = cosh(x);
//     printf("cos(%.2f) = %.2f\n", x, res);
//
//     return 0;
// }

double perimeter (double a, double b, double c) {
    return a + b + c;
}

int main() {
    double a, b, c;
    printf("Enter the first side of the triangle: ");
    scanf("%lf", &a);
    printf("Enter the second side of the triangle: ");
    scanf("%lf", &b);
    printf("Enter the third side of the triangle: ");
    scanf("%lf", &c);
    printf("Perimeter = %.2lf\n", perimeter(a, b, c));
}

