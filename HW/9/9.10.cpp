#include <stdio.h>
#include <stdlib.h>

int** create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;

    int **matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) return NULL;

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void free_matrix(int **matrix, int rows) {
    if (matrix == NULL) return;

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void input_matrix(int **matrix, int rows, int cols) {
    if (matrix == NULL) return;

    printf("Enter matrix elements (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    if (matrix == NULL) return;

    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int** multiply_matrices(int **A, int rowsA, int colsA, int **B, int rowsB, int colsB) {
    if (colsA != rowsB) {
        printf("Error: Cannot multiply - columns of A (%d) must equal rows of B (%d)\n", colsA, rowsB);
        return NULL;
    }

    int **result = create_matrix(rowsA, colsB);
    if (result == NULL) return NULL;

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main() {
    int num_matrices;

    printf("Enter number of matrices: ");
    scanf("%d", &num_matrices);

    if (num_matrices <= 0) {
        printf("Error: Number of matrices must be positive.\n");
        return 1;
    }

    int ***matrices = (int***)malloc(num_matrices * sizeof(int**));
    int *rows = (int*)malloc(num_matrices * sizeof(int));
    int *cols = (int*)malloc(num_matrices * sizeof(int));

    if (matrices == NULL || rows == NULL || cols == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < num_matrices; i++) {
        printf("\nMatrix %d:\n", i + 1);
        printf("Enter rows: ");
        scanf("%d", &rows[i]);
        printf("Enter columns: ");
        scanf("%d", &cols[i]);

        matrices[i] = create_matrix(rows[i], cols[i]);
        if (matrices[i] == NULL) {
            printf("Error: Failed to create matrix %d\n", i + 1);
            for (int j = 0; j < i; j++) {
                free_matrix(matrices[j], rows[j]);
            }
            free(matrices);
            free(rows);
            free(cols);
            return 1;
        }

        input_matrix(matrices[i], rows[i], cols[i]);
    }

    int **result = NULL;
    int result_rows = 0, result_cols = 0;

    if (num_matrices == 1) {
        result_rows = rows[0];
        result_cols = cols[0];
        result = create_matrix(result_rows, result_cols);
        if (result != NULL) {
            for (int i = 0; i < result_rows; i++) {
                for (int j = 0; j < result_cols; j++) {
                    result[i][j] = matrices[0][i][j];
                }
            }
        }
    } else {
        result_rows = rows[0];
        result_cols = cols[0];
        result = create_matrix(result_rows, result_cols);

        if (result != NULL) {
            for (int i = 0; i < result_rows; i++) {
                for (int j = 0; j < result_cols; j++) {
                    result[i][j] = matrices[0][i][j];
                }
            }

            for (int i = 1; i < num_matrices; i++) {
                int **temp = multiply_matrices(result, result_rows, result_cols,
                                             matrices[i], rows[i], cols[i]);
                if (temp == NULL) {
                    printf("Error: Multiplication failed at step %d\n", i + 1);
                    break;
                }

                free_matrix(result, result_rows);
                result = temp;
                result_rows = rows[0];  // Result rows remain from first matrix
                result_cols = cols[i];  // Result columns come from current matrix
            }
        }
    }

    printf("\n=== RESULTS ===\n");

    for (int i = 0; i < num_matrices; i++) {
        printf("\nInput Matrix %d:\n", i + 1);
        print_matrix(matrices[i], rows[i], cols[i]);
    }

    if (result != NULL) {
        printf("\nProduct of all matrices:\n");
        print_matrix(result, result_rows, result_cols);
    } else {
        printf("\nCould not calculate product of all matrices.\n");
    }

    for (int i = 0; i < num_matrices; i++) {
        free_matrix(matrices[i], rows[i]);
    }
    free(matrices);
    free(rows);
    free(cols);

    if (result != NULL) {
        free_matrix(result, result_rows);
    }

    printf("\nProgram completed successfully.\n");
    return 0;
}