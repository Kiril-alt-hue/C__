#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t num;
    printf("num = ");
    scanf("%u", &num);

    uint32_t first8 = num & 0xFF;
    uint32_t last8 = (num >> 24) & 0xFF;
    uint32_t middle = num & 0x00FFFF00;

    uint32_t result = (first8 << 24) | middle | last8;

    printf("%u\n", result);
    printf("%08X\n", result);

    return 0;
}