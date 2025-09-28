#include <stdio.h>

int main() {
    int x1 = -99, x2 = -99, x3 = -99;
    int x;
    int n = 4;
    int minPos = 0;
    int minValue = 0;

    while (1) {
        x = x3 + x1 + 100; // recurrence: x_n = x_{n-1} + x_{n-3} + 100

        if (x > 0) {
            if (minPos == 0 || x < minValue) {
                minValue = x;
                minPos = n;
            }
            break;
        }

        x1 = x2;
        x2 = x3;
        x3 = x;
        n++;
    }

    printf("The smallest positive term is x_%d = %d\n", minPos, minValue);

    return 0;
}
