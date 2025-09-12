#include <stdio.h>

void task3_5() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d%d", &x, &y);
    int min_num, max_num;
    if (x > y) {
        max_num = x;
        min_num = y;
        printf("%d is greater than %d", min_num, max_num);
    }
    else {
        printf("%d is greater than %d", y, x);

    }
}

int main() {
    task3_5();
}