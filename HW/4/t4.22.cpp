#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n (n >= 3): ");
    if (scanf("%d", &n) != 1 || n < 3) {
        printf("Invalid n. Need n >= 3.\n");
        return 1;
    }

    int prev, curr, next;
    int count = 0;

    scanf("%d", &prev);
    scanf("%d", &curr);

    for (int i = 3; i <= n; i++) {
        scanf("%d", &next);

        if (curr > prev && curr > next) {
            count++;
        }



        prev = curr;
        curr = next;
    }

    printf("Number of elements greater than both neighbors: %d\n", count);
    return 0;
}
