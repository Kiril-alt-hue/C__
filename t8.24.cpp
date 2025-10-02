#include <stdio.h>

#define N 100
#define M 100

int main() {
    int n, m;
    int matrix[N][M];
    int i, j;

    printf("Enter number of rows (n): ");
    scanf("%d", &n);
    printf("Enter number of columns (m): ");
    scanf("%d", &m);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int minVal = matrix[0][0], maxVal = matrix[0][0];
    int minRow = 0, maxRow = 0;


    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minRow = i;
            }
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
            }
        }
    }


    if (minRow != maxRow) {
        for (j = 0; j < m; j++) {
            int temp = matrix[minRow][j];
            matrix[minRow][j] = matrix[maxRow][j];
            matrix[maxRow][j] = temp;
        }
    }

    printf("\nMatrix after swapping rows with min and max elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
