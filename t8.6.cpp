#include <stdio.h>

#define MAX 100

int main() {
    int N, M;
    int k;
    int A[MAX][MAX];

    printf("Enter number of rows N (<=100): ");
    scanf("%d", &N);
    printf("Enter number of columns M (<=100): ");
    scanf("%d", &M);

    printf("Enter diagonal index k (i - j = k): ");
    scanf("%d", &k);

    printf("Enter matrix elements row by row:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int sum = 0;
    int found = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i - j == k) {
                sum += A[i][j];
                found = 1;
            }
        }
    }

    if (found) {
        printf("Sum of elements along diagonal i-j=%d is %d\n", k, sum);
    } else {
        printf("0\n");
    }

    return 0;
}
