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

void task3_7b() {
    double a, b, c;
    printf("Please enter a, b, c for biquadratic equation (ax^4 + bx^2 + c = 0): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Equation has infinitely many solutions.\n");
            } else {
                printf("No solution.\n");
            }
        } else {
            double y = -c / b;
            if (y < 0) {
                printf("No real roots.\n");
            } else if (y == 0) {
                printf("One root: x = 0\n");
            } else {
                double x1 = sqrt(y);
                double x2 = -sqrt(y);
                printf("Two roots: x1 = %.4lf, x2 = %.4lf\n", x1, x2);
            }
        }
        return;
    }

    double D = b * b - 4 * a * c;
    if (D < 0) {
        printf("No real roots.\n");
        return;
    }

    double y1 = (-b + sqrt(D)) / (2 * a);
    double y2 = (-b - sqrt(D)) / (2 * a);

    int found = 0;

    if (y1 >= 0) {
        if (y1 == 0) {
            printf("Root: x = 0\n");
        } else {
            double r1 = sqrt(y1);
            double r2 = -sqrt(y1);
            printf("Roots from y1: x1 = %.4lf, x2 = %.4lf\n", r1, r2);
        }
        found = 1;
    }

    if (y2 >= 0 && D != 0) {
        if (y2 == 0) {
            printf("Root: x = 0\n");
        } else {
            double r3 = sqrt(y2);
            double r4 = -sqrt(y2);
            printf("Roots from y2: x3 = %.4lf, x4 = %.4lf\n", r3, r4);
        }
        found = 1;
    }

    if (!found) {
        printf("No real roots.\n");
    }
}

int main() {
    task3_7a();
    task3_7b();
    return 0;
}
