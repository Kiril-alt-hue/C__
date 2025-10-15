#include "file_filter11.2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void createFilteredFile(const char* sourceFilename, const char* destFilename, double a) {
    FILE* sourceFile = fopen(sourceFilename, "r");
    if (!sourceFile) {
        perror("Failed to open source file F");
        return;
    }

    FILE* destFile = fopen(destFilename, "w");
    if (!destFile) {
        perror("Failed to create file G");
        fclose(sourceFile);
        return;
    }

    double number;
    while (fscanf(sourceFile, "%lf", &number) == 1) {
        if (fabs(number) < a) {
            fprintf(destFile, "%f ", number);
        }
    }

    printf("File '%s' was created successfully.\n", destFilename);
    fclose(sourceFile);
    fclose(destFile);
}

void removeElementsFromFile(const char* filename, double a) {
    FILE* sourceFile = fopen(filename, "r");
    if (!sourceFile) {
        perror("Failed to open file F for modification");
        return;
    }

    const char* tempFilename = "temp.txt";
    FILE* tempFile = fopen(tempFilename, "w");
    if (!tempFile) {
        perror("Failed to create a temporary file");
        fclose(sourceFile);
        return;
    }

    double number;
    while (fscanf(sourceFile, "%lf", &number) == 1) {
        if (fabs(number) >= a) {
            fprintf(tempFile, "%f ", number);
        }
    }

    fclose(sourceFile);
    fclose(tempFile);


    if (remove(filename) != 0) {
        perror("Error deleting the original file F");
        return;
    }

    if (rename(tempFilename, filename) != 0) {
        perror("Error renaming the temporary file");
        return;
    }

    printf("Elements were successfully removed from file '%s'.\n", filename);
}

void printFileContents(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open '%s' for reading.\n", filename);
        return;
    }

    printf("Contents of file '%s': [ ", filename);
    double number;
    while (fscanf(file, "%lf", &number) == 1) {
        printf("%g ", number);
    }
    printf("]\n");
    fclose(file);
}