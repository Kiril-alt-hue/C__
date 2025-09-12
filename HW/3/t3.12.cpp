#include <stdio.h>

int main() {
    double a, b, c, max, x, y;

    printf("Enter sides a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);


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


    if (max * max == x * x + y * y) {
        printf("Right triangle.\n");
    } else if (max * max < x * x + y * y) {
        printf("Acute triangle.\n");
    } else {
        printf("Obtuse triangle.\n");
    }

    return 0;
}
