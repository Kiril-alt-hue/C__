#include <stdio.h>

void task3_1a(unsigned n) { //void - don`t return
    unsigned last_digit = n % 10;
    unsigned second_digit = (n / 10) % 10;
    unsigned first_digit = n / 100;

    printf("1st num: %u, second: %u, third: %u", first_digit, second_digit, last_digit);

}

int main() {

    unsigned n;
    printf("Enter number: ");
    scanf_s("%u", &n);
    if (n>99 || n<=999) {
        task3_1a(n);
    }
    return 0;
}