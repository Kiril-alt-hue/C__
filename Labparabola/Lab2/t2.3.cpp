#include <stdio.h>
#include <math.h>

double area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double a, b, c;
    printf("Enter the first side of the triangle: ");
    scanf("%lf", &a);
    printf("Enter the second side of the triangle: ");
    scanf("%lf", &b);
    printf("Enter the third side of the triangle: ");
    scanf("%lf", &c);

    printf("Area = %.2lf\n", area(a, b, c));
}