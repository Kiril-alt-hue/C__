#include "functions11.3.h"

int is_perfect_square(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    int root = (int)sqrt((double)n);
    return root * root == n;
}

void create_file_F(const char *filename) {
    FILE *file_F = fopen(filename, "w");
    if (file_F == NULL) {
        printf("Error open file %s\n", filename);
        return;
    }

    int number;
    printf("Enter int numbers (enter 0 to end):\n");

    while (1) {
        scanf("%d", &number);
        if (number == 0) {
            break;
        }
        fprintf(file_F, "%d\n", number);
    }

    fclose(file_F);
    printf("File %s succesfully created.\n", filename);
}


void create_file_G(const char *source_filename, const char *dest_filename) {
    FILE *file_F = fopen(source_filename, "r");
    if (file_F == NULL) {
        printf("Error: impossible read file %s\n", source_filename);
        return;
    }

    FILE *file_G = fopen(dest_filename, "w");
    if (file_G == NULL) {
        printf("Error create file %s\n", dest_filename);
        fclose(file_F);
        return;
    }

    int number;
    while (fscanf(file_F, "%d", &number) != EOF) {
        if (is_perfect_square(number)) {
            fprintf(file_G, "%d\n", number);
        }
    }


    fclose(file_F);
    fclose(file_G);
    printf("File %s successfully created.\n", dest_filename);
}