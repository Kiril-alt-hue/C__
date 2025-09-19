#include <stdio.h>
#include <math.h>

double lenght (double x1, double y1, double x2, double y2) {
    double length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return length;
}

double area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double a_1, a_2;
    printf("Enter coordinates point A: ");
    scanf("%lf %lf", &a_1, &a_2);

    double b_1, b_2;
    printf("Enter coordinates point B: ");
    scanf("%lf %lf", &b_1, &b_2);

    double c_1, c_2;
    printf("Enter coordinates point C: ");
    scanf("%lf %lf", &c_1, &c_2);

    double AB = lenght(a_1, a_2, b_1, b_2);
    double BC = lenght(b_1, b_2, c_1, c_2);
    double AC = lenght(c_1, c_2, a_1, a_2);

    printf("Area = %.2lf\n", area(AB, BC, AC));

    return 0;
}