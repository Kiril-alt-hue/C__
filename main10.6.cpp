#include <stdio.h>
#include "time10.6.h" /

int main() {
    struct Time currentTime;

    printf("--- Time Input ---\n");
    inputTime(&currentTime);

    printf("\n--- Time Output ---\n");
    printTime(&currentTime);

    return 0;
}