#include <stdio.h>
#define N 5

int main() {
    int mas[N] = {1, 2, 3, 4, 5}, n;
    int k = 0;
    printf("n = ");
    scanf("%d", &n);

    int x = sizeof(mas) / sizeof(mas[0]); //підрахування розміру масиву

    for (int i = 0; i < x; i++) {
        if (mas[i] < n) {
            k++;
        }
    }
    printf("k = %d\n", k);
}