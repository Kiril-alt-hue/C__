#include "file_processor11.9.h"
#include <stdio.h>
#include <stdlib.h>

void create_test_file_f(int use_odd_set) {
    FILE* file = fopen(FILE_F, "w");
    if (file == NULL) {
        perror("Error creating F.txt");
        return;
    }

    fprintf(file, "10\n");
    fprintf(file, "-5\n");
    fprintf(file, "0\n"); // Нулі ігноруються
    fprintf(file, "20\n");
    fprintf(file, "-15\n");
    fprintf(file, "30\n");
    fprintf(file, "-25\n");
    fprintf(file, "40\n");
    fprintf(file, "-35\n");

    if (use_odd_set) {
        // Додаємо п'яту пару, роблячи загальну кількість (5) непарною
        fprintf(file, "50\n");
        fprintf(file, "-45\n");
        // Тепер у файлі 5 додатних і 5 від'ємних
    }
    // Якщо use_odd_set == 0, у файлі буде 4 додатних і 4 від'ємних

    fclose(file);
    printf("Created test file %s (use_odd_set = %d)\n", FILE_F, use_odd_set);
}


int count_pos_neg(const char* filename, int* pos_count, int* neg_count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for counting");
        return -1;
    }

    *pos_count = 0;
    *neg_count = 0;
    int number;

    while (fscanf(file, "%d", &number) == 1) {
        if (number > 0) {
            (*pos_count)++;
        } else if (number < 0) {
            (*neg_count)++;
        }

    }

    fclose(file);
    return 0;
}


int separate_numbers_to_h(const char* file_f_name, const char* file_h_name) {
    FILE* file_f;
    FILE* file_h;
    int number;


    file_f = fopen(file_f_name, "r");
    file_h = fopen(file_h_name, "w");
    if (file_f == NULL || file_h == NULL) {
        perror("Error opening files for positive separation");
        if (file_f) fclose(file_f);
        if (file_h) fclose(file_h);
        return -1;
    }

    while (fscanf(file_f, "%d", &number) == 1) {
        if (number > 0) {
            fprintf(file_h, "%d\n", number);
        }
    }
    fclose(file_f);
    fclose(file_h);


    file_f = fopen(file_f_name, "r");
    file_h = fopen(file_h_name, "a");
    if (file_f == NULL || file_h == NULL) {
        perror("Error opening files for negative separation");
        if (file_f) fclose(file_f);
        if (file_h) fclose(file_h);
        return -1;
    }

    while (fscanf(file_f, "%d", &number) == 1) {
        if (number < 0) {
            fprintf(file_h, "%d\n", number);
        }
    }
    fclose(file_f);
    fclose(file_h);

    return 0;
}


int process_files_from_h(const char* file_g_name, const char* file_h_name, int pos_count, int neg_count) {

    int total_count = pos_count + neg_count;

    int* all_numbers = (int*)malloc(total_count * sizeof(int));
    if (all_numbers == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return -1;
    }

    FILE* file_h = fopen(file_h_name, "r");
    if (file_h == NULL) {
        perror("Error opening H for processing");
        free(all_numbers);
        return -1;
    }

    for (int i = 0; i < total_count; ++i) {
        if (fscanf(file_h, "%d", &all_numbers[i]) != 1) {
            fprintf(stderr, "Error reading from H, file corrupted or count mismatch.\n");
            fclose(file_h);
            free(all_numbers);
            return -1;
        }
    }
    fclose(file_h);

    int* pos_nums = all_numbers;
    int* neg_nums = all_numbers + pos_count;

    FILE* file_g = fopen(file_g_name, "w");
    if (file_g == NULL) {
        perror("Error opening G for writing");
        free(all_numbers);
        return -1;
    }

    int num_pairs = pos_count / 2; // Кількість повних пар (2+2)
    int num_leftover = pos_count % 2; // 1, якщо непарна; 0, якщо парна
    int p_idx = 0; // Індекс для додатних
    int n_idx = 0; // Індекс для від'ємних

    printf("Processing %d full pairs (pos, pos, neg, neg)...\n", num_pairs);


    for (int i = 0; i < num_pairs; ++i) {
        fprintf(file_g, "%d\n", pos_nums[p_idx++]);
        fprintf(file_g, "%d\n", pos_nums[p_idx++]);

        fprintf(file_g, "%d\n", neg_nums[n_idx++]);
        fprintf(file_g, "%d\n", neg_nums[n_idx++]);
    }


    if (num_leftover > 0) {
        printf("--- Leftover numbers (not written to G) ---\n");
        printf("Last positive: %d\n", pos_nums[p_idx]);
        printf("Last negative: %d\n", neg_nums[n_idx]);
        printf("--------------------------------------------\n");
    }

    fclose(file_g);
    free(all_numbers);
    remove(file_h_name);

    return 0;
}
