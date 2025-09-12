#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    unsigned n;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);
    y=x;
    for (unsigned int i = 0; i<n; i++) {
        y=sin(y);
    }
    printf("y=%lf\n", y);
    return 0;
}