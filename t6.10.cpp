#include <stdio.h>

int main() {
    unsigned int m;
    printf("Enter a natural number m: ");
    scanf("%u", &m);

    int bits = sizeof(m) * 8;

    // Extract lower 8 bits
    unsigned int low8 = m & 0xFF;

    // Extract upper 8 bits
    unsigned int high8 = (m >> (bits - 8)) & 0xFF;

    // Clear original high 8 bits and low 8 bits
    unsigned int middle = m & ~((0xFFu << (bits - 8)) | 0xFFu);

    // Swap them
    unsigned int result = middle | (low8 << (bits - 8)) | high8;

    printf("Result (decimal): %u\n", result);
    printf("Result (hex): 0x%X\n", result);

    return 0;
}
