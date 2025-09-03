#include <stdio.h>

int main() {
    double a, b, z;
    printf("Enter a and b: ");
    scanf("%lf %lf", &a, &b);

    z = 2 / (1/a + 1/b);
    printf("%lf", z);
}