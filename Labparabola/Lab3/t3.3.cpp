#include <stdio.h>

void task3_3() {
    int a, b, c;
    int res1;
    long long res2;
    int inn_corr = scanf("%d %d %d", &a, &b, &c);
    if (inn_corr != 3) {
        printf("Incorrect input\n");
        return;
    }
    res1 = a * b * c;
    printf("r1 = %d\n", res1);

    res2 =(long long) a * (long long) b * (long long)c;
    printf("r2 = %d\n", res2);

}

int main() {
    task3_3();

    return 0;
}