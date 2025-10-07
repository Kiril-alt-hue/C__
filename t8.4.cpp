#include <stdio.h>

#define MAX 25

void InputMatrix(double matrix[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("Enter row %d (%d numbers separated by space): ", i + 1, n);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void OutputMatrix(double matrix[MAX][MAX], int m, int n) {
    printf("\nMatrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    double matrix[MAX][MAX];

    printf("Enter number of rows (m < 25): ");
    scanf("%d", &m);
    printf("Enter number of columns (n < 25): ");
    scanf("%d", &n);

    InputMatrix(matrix, m, n);
    OutputMatrix(matrix, m, n);

    return 0;
}
