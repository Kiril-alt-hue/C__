#include <stdio.h>

void check_endianness() {
    unsigned int num = 0x1A2B3C4D;
    unsigned char *byte = (unsigned char *)&num;

    printf("Number 0x1A2B3C4D in memory save as:\n");

    for (int i = 0; i < sizeof(num); i++) {
        printf("Bite %d: 0x%02X\n", i, byte[i]);
    }

    if (byte[0] == 0x4D) {
        printf("Arch: Little Endian\n");
    } else if (byte[0] == 0x1A) {
        printf("Arch: Big Endian\n");
    } else {
        printf("Arch: Middle Endian (Mixed)\n");
    }
}

int main() {
    check_endianness();
    return 0;
}