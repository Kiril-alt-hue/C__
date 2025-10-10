#include <stdio.h>
#include "time10.6.h"

void inputTime(struct Time *t) {
    printf("Enter hour (0-23): ");
    scanf("%d", &t->hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &t->minute);

    printf("Enter second (0-59): ");
    scanf("%d", &t->second);
}
void printTime(const struct Time *t) {
    printf("The time is: %02d:%02d:%02d\n", t->hour, t->minute, t->second);
}