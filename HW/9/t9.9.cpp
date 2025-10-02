#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    int **matrix;


    printf("Enter the number of rows (N): ");
    scanf("%d", &N);
    printf("Enter the number of columns (M): ");
    scanf("%d", &M);


    if (N <= 0 || M <= 0) {
        printf("Error: Dimensions must be positive integers.\n");
        return 1;
    }


    matrix = (int **)malloc(N * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(M * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed!\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }


    printf("\nGenerated matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 100;
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }


    int new_N = N + 1;


    int **new_matrix = (int **)realloc(matrix, new_N * sizeof(int *));
    if (new_matrix == NULL) {
        printf("Memory reallocation failed!\n");
        for (int i = 0; i < N; i++) {
            free(matrix[i]);
        }
        free(matrix);
        return 1;
    }
    matrix = new_matrix;

    for (int i = N; i > 0; i--) {
        matrix[i] = matrix[i - 1];
    }


    matrix[0] = (int *)malloc(M * sizeof(int));
    if (matrix[0] == NULL) {
        printf("Memory allocation for new row failed!\n");
        // Free all memory
        for (int i = 1; i < new_N; i++) {
            free(matrix[i]);
        }
        free(matrix);
        return 1;
    }


    for (int j = 0; j < M; j++) {
        matrix[0][j] = rand() % 100;
    }


    printf("\nMatrix after adding a row at the beginning:\n");
    for (int i = 0; i < new_N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < new_N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}