#include <stdio.h>
#include <stdlib.h>

int main() {

    double x;
    printf("x = ");
    scanf("%lf",&x);
    double y = x * x;
    printf("y(%lf) = %4.2lf ", x, y);
    return 0;
}