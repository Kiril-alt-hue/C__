#include "arrayutils11_1.h"
#include <stdio.h>

void writeArrayToFile(const char* filename, const double* arr, int size) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        fprintf(stderr, "Помилка: Не вдалося відкрити файл %s для запису.\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%f ", arr[i]);
    }

    fclose(file);
    printf("Масив успішно записано у файл '%s'.\n", filename);
}

void readAndPrintArrayFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Помилка: Не вдалося відкрити файл %s для читання.\n", filename);
        return;
    }

    printf("\nВміст файлу '%s':\n", filename);

    double number;
    int isFirstElement = 1;

    while (fscanf(file, "%lf", &number) == 1) {
        if (isFirstElement) {
            printf("%g", number);
            isFirstElement = 0;
        } else {
            printf(", %g", number);
        }
    }

    printf("\n");

    fclose(file);
}

