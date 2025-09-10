#include <stdio.h>

void task3_2(unsigned n) {
    unsigned last_digit = n % 10;
    unsigned second_digit = (n / 10) % 10;
    unsigned first_digit = n / 100;

    if ((last_digit == second_digit) ||
        (first_digit == second_digit) ||
        (first_digit == last_digit)) {
        return;
    }
    unsigned r1 = 100 * first_digit + 10* second_digit + last_digit;
    unsigned r2 = 100 * first_digit + 10* last_digit + second_digit;

    unsigned r3 = 100 * second_digit + 10* last_digit + first_digit;
    unsigned r4 = 100 * second_digit + 10* first_digit + last_digit;

    unsigned r5 = 100 * last_digit + 10* first_digit + second_digit;
    unsigned r6 = 100 * last_digit + 10* second_digit + first_digit;

    printf("%u, %u, %u, %u, %u, %u", r1, r2, r3, r4, r5, r6);
}

int main() {
    unsigned n;
    printf("Enter number: ");
    scanf_s("%u", &n);
    if (n>99 || n<=999) {
        task3_2(n);
    }
    return 0;
}