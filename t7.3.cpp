#include <stdio.h>
#include <math.h>

#define N 10

// int greater_Euler(const double arr[N], size_t) {
//
// }
// int greater_Euler(const double* arr_start, const double* arr_end) {
//
// }
int greater_Euler(double arr[N]) {
    int k =0;
    for (int i = 0; i < N; i++) {
        k += arr[i]>exp(1) ? 1 : 0;
    }
    return k;
}


int main() {
    double arr[N];

    for (int i = 0; i < N; i++) {
        printf("arr[%d] = ", i);
        scanf("%lf", &arr[i]);
    }

    int result = greater_Euler(arr);
    printf("\nresult = %d", result);
}