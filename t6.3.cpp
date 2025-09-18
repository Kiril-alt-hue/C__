#include <stdio.h>
#include <stdint.h>

void task3();


int main() {
    int task_index = 1;

    if (task_index == 1) {
        task3();
    }
}

void task3() {
    uint64_t m;
    int j;

    printf("m =  ");
    scanf("%llu", &m);

    printf("j (from 0 to 63): ");
    scanf("%d", &j);

    if (j < 0 || j > 63) {
        printf("Uncorrect input j\n");
        return;
    }
    uint64_t mask = ~(1ULL << j);

    uint64_t result = m & mask;


    printf ("%llu\n", result);
    printf("%016llX\n", result);

    return;
}
