#include <stdio.h>

#define MAX_SIZE 20


void inputVector(double v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        scanf("%lf", &v[i]);
    }
}


void outputVector(double v[], int n) {
    printf("(");
    for (int i = 0; i < n; i++) {
        printf("%.2lf", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf(")\n");
}


void sumVectors(double a[], double b[], double res[], int n) {
    for (int i = 0; i < n; i++) {
        res[i] = a[i] + b[i];
    }
}


double dotProduct(double a[], double b[], int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    return res;
}

int main() {
    int n;
    double v1[MAX_SIZE], v2[MAX_SIZE], sum[MAX_SIZE];

    printf("Enter the dimension of vectors (n < 20): ");
    scanf("%d", &n);

    if (n <= 0 || n >= MAX_SIZE) {
        printf("Invalid n!\n");
        return 1;
    }

    printf("Enter the first vector:\n");
    inputVector(v1, n);

    printf("Enter the second vector:\n");
    inputVector(v2, n);

    sumVectors(v1, v2, sum, n);

    printf("\nFirst vector: ");
    outputVector(v1, n);

    printf("Second vector: ");
    outputVector(v2, n);

    printf("Sum of vectors: ");
    outputVector(sum, n);

    double scalar = dotProduct(v1, v2, n);
    printf("Dot product: %.2lf\n", scalar);

    return 0;
}
