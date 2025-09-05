#include <stdio.h>
#include <math.h>

double lenght (double x1, double y1, double x2, double y2) {
    double length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return length;
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

    double AB =
    return 0;
}