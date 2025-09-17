#include <stdio.h>

void task2();


int main() {
    int task_index = 1;

    if (task_index == 1) {
        task2();
    }
}

void task2() {
    int k;
    unsigned n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);

    m = n | (1<<k);
    printf("%x or %d", m, m);
}