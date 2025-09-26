#include <stdio.h>

int fib_index(unsigned long long a) {
    if (a == 0) return 0;

    unsigned long long prev = 0, curr = 1, next;
    int index = 1;

    while (curr <= a) {
        next = prev + curr;
        prev = curr;
        curr = next;
        index++;
    }

    return index - 1;
}

int main() {
    unsigned long long a;
    printf("Enter a number: ");
    scanf("%llu", &a);

    int index = fib_index(a);
    printf("The largest Fibonacci number not exceeding %llu is F(%d)\n", a, index);

    return 0;
}