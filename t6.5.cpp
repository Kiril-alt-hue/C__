#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t num;
    printf("num = ");
    scanf("%u", &num);

    int maxCount = 0;
    int currentCount = 0;

    for (int i = 0; i < 32; i++) {
        if (num & (1U << i)) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0;
        }
    }

    printf("%d\n", maxCount);
    return 0;
}