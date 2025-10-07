#include <stdio.h>
#include <stdlib.h>


double* create_matrix(unsigned n) {
    return (double*)calloc(n * n, sizeof(double));
}


void free_matrix(double* mat) {
    free(mat);
}


void input_matrix(double* mat, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            printf("a[%u][%u] = ", i, j);
            scanf("%lf", &mat[i * n + j]);
        }
    }
}


void print_matrix(double* mat, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            printf("%8.2lf ", mat[i * n + j]);
        }
        printf("\n");
    }
}


double* multiply_matrix(double* A, double* B, unsigned n) {
    double* C = create_matrix(n);
    if (!C) return NULL;

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            for (unsigned k = 0; k < n; k++) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
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
    double* A = create_matrix(n);
    input_matrix(A, n);

    printf("\nEnter second matrix:\n");
    double* B = create_matrix(n);
    input_matrix(B, n);

    double* C = multiply_matrix(A, B, n);

    printf("\nResult (A * B):\n");
    print_matrix(C, n);


    free_matrix(A);
    free_matrix(B);
    free_matrix(C);

    return 0;
}
