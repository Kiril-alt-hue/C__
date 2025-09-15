#include <stdio.h>
#include <math.h>

double Rosenbrock(double x, double y) {
    //double res;
    //res = 100 * pow((pow(x, 2) - y), 2) + pow((x - 1), 2);
    //return res;
    double a = 10 * (x * x - y);
    double b = x - 1;
    return a*a + b*b;
}

int main() {
    // double x, y;
    // printf("Enter x: ");
    // scanf("%lf", &x);
    // printf("Enter y: ");
    // scanf("%lf", &y);

    printf("%g\n", Rosenbrock(1, 1));
    printf("%g\n", Rosenbrock(2, 4));
    printf("%g\n", Rosenbrock(2, 3));


}