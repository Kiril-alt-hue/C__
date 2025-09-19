#include <stdio.h>
#include <math.h>

int main() {
    double x;
    printf("Enter a real number x: ");
    scanf("%lf", &x);

    double intPart, fracPart;
    fracPart = modf(x, &intPart);

    printf("Integer part: %.0lf\n", intPart);
    printf("Fractional part: %.6lf\n", fracPart);
    printf("Ceil: %.0lf\n", ceil(x));
    printf("Floor: %.0lf\n", floor(x));
    printf("Rounded: %.0lf\n", round(x));

    return 0;
}
