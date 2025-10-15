#include <stdio.h>
#include "file_filter11.2.h"


void setupSourceFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Could not create the initial source file");
        return;
    }
    fprintf(file, "10.5 -2.0 5.1 -8.3 1.1 20.0 -0.5 4.99");
    fclose(file);
}

int main() {
    const char* F_FILENAME = "F.txt";
    const char* G_FILENAME = "G.txt";
    double a;


    setupSourceFile(F_FILENAME);
    printf("--- Initial State ---\n");
    printFileContents(F_FILENAME);


    printf("\nEnter a real number a > 0: ");
    if (scanf("%lf", &a) != 1 || a <= 0) {
        printf("Error: you must enter a positive number.\n");
        return 1;
    }


    printf("\n--- Step 1: Creating File G ---\n");
    createFilteredFile(F_FILENAME, G_FILENAME, a);
    printFileContents(G_FILENAME);


    printf("\n--- Step 2: Modifying File F ---\n");
    removeElementsFromFile(F_FILENAME, a);
    printFileContents(F_FILENAME);

    return 0;
}