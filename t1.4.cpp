#include <stdio.h>
#include <math.h>
int main() {
    int G = 6.67e-11;
    int m1, m2, r;

    printf("Enter masses m1: ");
    scanf("%d", &m1);
    printf("Enter masses m2: ");
    scanf("%d", &m2);
    printf("Enter distance r: ");
    scanf("%d", &r);

    double F = G * m1 * m2/pow(r, 2);

    printf("F = %g");
}