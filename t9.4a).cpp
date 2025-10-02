#include <stdio.h>
#include <stdlib.h>


double** create_matrix(unsigned n) {
    double** mat = (double**)malloc(n * sizeof(double*));
    if (!mat) return NULL;

    for (unsigned i = 0; i < n; i++) {
        mat[i] = (double*)calloc(n, sizeof(double));
        if (!mat[i]) {
            for (unsigned j = 0; j < i; j++) free(mat[j]);
            free(mat);
            return NULL;
        }
    }
    return mat;
}


void free_matrix(double** mat, unsigned n) {
    if (!mat) return;
    for (unsigned i = 0; i < n; i++) free(mat[i]);
    free(mat);
}


void input_matrix(double** mat, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            printf("a[%u][%u] = ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }
}


void print_matrix(double** mat, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            printf("%8.2lf ", mat[i][j]);
        }
        printf("\n");
    }
}


double** multiply_matrix(double** A, double** B, unsigned n) {
    double** C = create_matrix(n);
    if (!C) return NULL;

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            for (unsigned k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    unsigned n;
    printf("Enter matrix dimension n: ");
    scanf("%u", &n);

    printf("\nEnter first matrix:\n");
    double** A = create_matrix(n);
    input_matrix(A, n);

    printf("\nEnter second matrix:\n");
    double** B = create_matrix(n);
    input_matrix(B, n);

    double** C = multiply_matrix(A, B, n);

    printf("\nResult (A * B):\n");
    print_matrix(C, n);

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}
