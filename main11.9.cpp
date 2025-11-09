#include <stdio.h>
#include "file_processor11.9.h"


void print_file_contents(const char* filename, const char* label) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("--- Cannot open %s to print ---\n", filename);
        return;
    }
    printf("--- Contents of %s (%s) ---\n", filename, label);
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        printf("%d\n", num);
    }
    printf("---------------------------------\n\n");
    fclose(file);
}


void run_test(int use_odd_set) {
    if (use_odd_set) {
        printf("\n======= TEST 1: ODD COUNT (5 pos, 5 neg) =======\n");
    } else {
        printf("\n======= TEST 2: EVEN COUNT (4 pos, 4 neg) =======\n");
    }

    create_test_file_f(use_odd_set);
    print_file_contents(FILE_F, "Original Data");

    int pos_count = 0;
    int neg_count = 0;
    if (count_pos_neg(FILE_F, &pos_count, &neg_count) != 0) {
        fprintf(stderr, "Failed to count. Aborting.\n");
        return;
    }

    printf("Result: %d positive, %d negative numbers found.\n", pos_count, neg_count);

    if (pos_count != neg_count || pos_count == 0) {
        printf("Error: Count of positive and negative numbers is not equal (or is zero). Aborting.\n");
        return;
    }

    if (separate_numbers_to_h(FILE_F, FILE_H) != 0) {
        fprintf(stderr, "Failed to separate numbers to H.txt. Aborting.\n");
        return;
    }

    if (process_files_from_h(FILE_G, FILE_H, pos_count, neg_count) != 0) {
        fprintf(stderr, "Failed to process H.txt. Aborting.\n");
        return;
    }

    printf("Processing complete. %s deleted.\n", FILE_H);
    print_file_contents(FILE_G, "Final G output");
    printf("==================================================\n");
}


int main() {
    run_test(1);
    run_test(0);

    return 0;
}
