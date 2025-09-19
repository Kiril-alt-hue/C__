#include <stdio.h>
#include <stdbool.h>


bool no_common_bits(unsigned int a, unsigned int b) {
    return (a & b) == 0;
}

int main() {
    unsigned int x, y;
    printf("Enter two natural numbers: ");
    scanf("%u %u", &x, &y);

    if (no_common_bits(x, y))
        printf("The numbers have no common set bits.\n");
    else
        printf("The numbers have common set bits.\n");

    return 0;
}
