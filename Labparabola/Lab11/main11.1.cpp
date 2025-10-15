#include <stdio.h>
#include <stdlib.h>
#include "arrayutils11_1.h"

int main() {
    int size;
    const char* FILENAME = "numbers.txt";

    printf("Введіть довжину масиву: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Некоректна довжина. Будь ласка, введіть додатне ціле число.\n");
        return 1;
    }

    double* array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        fprintf(stderr, "Помилка виділення пам'яті.\n");
        return 1;
    }

    printf("Введіть %d дійсних чисел через пробіл:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%lf", &array[i]);
    }

    writeArrayToFile(FILENAME, array, size);

    readAndPrintArrayFromFile(FILENAME);

    free(array);

    return 0;
}