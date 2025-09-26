#include <stdio.h>
#define N 5


int max_el(int arr[N]) {
    int max = arr[0];
    for (int i = 0; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[N];

    for (int i = 0; i < N; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int max_element = max_el(arr);
    printf("\nmax_el = %d", max_element);
}