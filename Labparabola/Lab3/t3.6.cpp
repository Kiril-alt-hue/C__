#include <stdio.h>
#include <math.h>

void task3_6() {
    double a, b, c;
    printf("Enter a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    double max_num, min_num;
    max_num = fmax(abs(a), fmax(abs(b), abs(c)));
    min_num = fmin(abs(a), fmin(abs(b), abs(c)));


    printf("The max number is: %d. The min number is: %d", max_num, min_num);
}

int main() {
    task3_6();
    return 0;
}