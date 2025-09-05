#include <stdio.h>
#include <math.h>

int main() {
    double x;
    int r1, r2;
    printf("Enter number: ");
    scanf("%lf", &x);
    r1 = (int) (x);
    printf("%d\n", r1);
    r2 = round(x);
    printf("%d", r2);

    return 0;

}