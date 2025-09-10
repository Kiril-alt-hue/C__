#include <cstdint>
#include <stdio.h>


uint16_t mult_task3_4(uint8_t x, uint8_t y) {
    return x * y;
}

void task3_4() {
    uint8_t x, y;
    printf("x, y: ");
    scanf_s("%hhu, %hhu", &x, &y);
    uint16_t z = mult_task3_4(x, y);
    printf("z = %u\n", z);
}

int main() {
    task3_4();

    return 0;
}