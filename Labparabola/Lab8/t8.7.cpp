#include <stdio.h>

#define MAX 10

double Determinant(double matrix[MAX][MAX], int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }

    double det = 0;
    double temp[MAX][MAX];

    for (int p = 0; p < n; p++) {
        int row = 1;
        for (int i = 1; i < n; i++) {
            int col = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                temp[row-1][col] = matrix[i][j];
                col++;
            }
            row++;
        }
        det += matrix[0][p] * Determinant(temp, n-1) * ((p % 2 == 0) ? 1 : -1);
    }

    return det;
}

int main() {
    int n;
    double matrix[MAX][MAX];

    printf("Enter size of square matrix (n <= 10): ");
    scanf("%d", &n);

    printf("Enter matrix elements row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    double det = Determinant(matrix, n);
    printf("Determinant = %.2lf\n", det);

    return 0;
}
