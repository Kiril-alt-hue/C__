#include <stdio.h>
#include <stdint.h>

void check_expressions(int x) {
    int y1 = ((x & (x-1)) > 0);
    int y2 = x & (-x);

    printf("For x = %d (0x%X):\n", x, x);
    printf("  y1 = ((x & (x-1)) > 0) = %d\n", y1);
    printf("  y2 = x & (-x) = %d (0x%X)\n", y2, y2);
    printf("\n");
}

int main() {
    check_expressions(0);     // 0000
    check_expressions(1);     // 0001
    check_expressions(2);     // 0010
    check_expressions(3);     // 0011
    check_expressions(4);     // 0100
    check_expressions(8);     // 1000
    check_expressions(12);    // 1100

    return 0;
}