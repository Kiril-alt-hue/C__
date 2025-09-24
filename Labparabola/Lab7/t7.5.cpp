#include <stdio.h>

#define N 50

int is_even(int arr[N], int n) {
    int el_even = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2) {
            el_even++;
        }
    }
    return el_even;
}

int is_odd(int arr[N], int n) {
    int el_odd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2) {
            continue;
        }
        else {
            el_odd++;
        }
    }
    return el_odd;
}

int main() {
    int arr[N];
    int n = 0;

    printf("If you want to stop, enter -1\n");

    for (int i = 0; i < N; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);

        if (arr[i] == -1) {
            break;
        }
        n++;
    }

    printf("\nYou entered %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int count_even = is_even(arr, n);
    printf("\nCount even elements: %d\n", count_even);

    int count_odd = is_odd(arr, n);
    printf("\nCount odd elements: %d\n", count_odd);
}