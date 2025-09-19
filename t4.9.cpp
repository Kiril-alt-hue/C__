#include <stdio.h>

int main() {
    int n;

    printf("Enter natural number n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: n must be a natural number (n >= 0)!\n");
        return 1;
    }

    int r = 0;
    int power = 1; // 2^0 = 1


    do {
        r++;
        power *= 2;
    } while (power <= n);


    printf("The smallest number of the form 2^r that exceeds %d is:\n", n);
    printf("2^%d = %d\n", r, power);

    return 0;
}