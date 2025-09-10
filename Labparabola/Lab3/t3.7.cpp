#include <stdio.h>
#include <math.h>

void task3_7a() {
    double a, b, c;
    printf("Please enter a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Equation has infinitely many solutions.\n");
            } else {
                printf("No solution.\n");
            }
        } else {
            double x = -c / b;
            printf("Linear equation, root: x = %.4lf\n", x);
        }
        return;
    }

    double discriminant = b * b - 4 * a * c;
    double x1, x2;

    if (discriminant < 0) {
        printf("No real roots.\n");
    } else if (discriminant == 0) {
        x1 = -b / (2 * a);
        printf("Only one root: x1 = %.4lf\n", x1);
    } else {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two roots: x1 = %.4lf, x2 = %.4lf\n", x1, x2);
    }
}

int main() {
    task3_7a();
    return 0;
}
