#include <stdio.h>

#define MAX 25

void TransposeMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}


void PrintMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];

    printf("Enter the size of the square matrix (n <= 25): ");
    scanf("%d", &n);

    printf("Enter matrix elements row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal matrix:\n");
    PrintMatrix(matrix, n);

    TransposeMatrix(matrix, n);

    printf("\nTransposed matrix:\n");
    PrintMatrix(matrix, n);

    return 0;
}
