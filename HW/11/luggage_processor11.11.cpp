#include "luggage_processor11.11.h"
#include <stdlib.h> // Для malloc, realloc, free
#include <string.h> // Для strcpy, strlen, strcspn
#include <math.h>   // Для fabs


void remove_newline(char* str) {
    str[strcspn(str, "\n\r")] = '\0';
}


char** load_surnames(const char* filename, int* surname_count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        *surname_count = 0;
        return NULL;
    }

    char** surnames = NULL;
    int count = 0;
    int capacity = 10; // Початкова ємність
    char buffer[MAX_LINE_LENGTH];


    surnames = (char**)malloc(capacity * sizeof(char*));
    if (surnames == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(file);
        *surname_count = 0;
        return NULL;
    }


    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        remove_newline(buffer); // Видаляємо '\n'


        if (strlen(buffer) == 0) continue;


        if (count >= capacity) {
            capacity *= 2; // Подвоюємо ємність
            char** temp = (char**)realloc(surnames, capacity * sizeof(char*));
            if (temp == NULL) {
                fprintf(stderr, "Error: Memory reallocation failed.\n");
                free_surnames(surnames, count);
                fclose(file);
                *surname_count = 0;
                return NULL;
            }
            surnames = temp;
        }


        surnames[count] = (char*)malloc(strlen(buffer) + 1); // +1 для '\0'
        if (surnames[count] == NULL) {
             fprintf(stderr, "Error: Memory allocation for string failed.\n");
             // ... обробка помилки ...
             continue;
        }
        strcpy(surnames[count], buffer);
        count++;
    }

    fclose(file);
    *surname_count = count;
    return surnames;
}


struct Luggage* load_luggage(const char* filename, int* luggage_count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        *luggage_count = 0;
        return NULL;
    }

    struct Luggage* luggage_list = NULL;
    int count = 0;
    int capacity = 10;
    char buffer[MAX_LINE_LENGTH];

    luggage_list = (struct Luggage*)malloc(capacity * sizeof(struct Luggage));
    if (luggage_list == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(file);
        *luggage_count = 0;
        return NULL;
    }


    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        if (count >= capacity) {
            capacity *= 2;
            struct Luggage* temp = (struct Luggage*)realloc(luggage_list, capacity * sizeof(struct Luggage));
            if (temp == NULL) {
                fprintf(stderr, "Error: Memory reallocation failed.\n");
                free_luggage(luggage_list);
                fclose(file);
                *luggage_count = 0;
                return NULL;
            }
            luggage_list = temp;
        }

        if (sscanf(buffer, "%d %d %lf",
                   &luggage_list[count].passenger_index,
                   &luggage_list[count].item_count,
                   &luggage_list[count].total_weight) == 3)
        {
            count++;
        } else {
             fprintf(stderr, "Warning: Skipping malformed line in luggage file: %s", buffer);
        }
    }

    fclose(file);
    *luggage_count = count;
    return luggage_list;
}

int find_similar_luggage_passengers(
    char** surnames,
    int surname_count,
    struct Luggage* luggage_list,
    int luggage_count,
    double max_weight_diff)
{
    int found_pair = 0;

    if (surname_count == 0 || luggage_count < 2) {
        printf("Not enough data to compare.\n");
        return 0;
    }

    printf("Searching for passenger pairs with similar luggage (weight diff <= %.1f kg)...\n",
           max_weight_diff);

    for (int i = 0; i < luggage_count; ++i) {
        for (int j = i + 1; j < luggage_count; ++j) {

            const struct Luggage* lug1 = &luggage_list[i];
            const struct Luggage* lug2 = &luggage_list[j];

            if (lug1->passenger_index >= surname_count || lug2->passenger_index >= surname_count) {
                fprintf(stderr, "Error: Invalid passenger index found in luggage data.\n");
                continue;
            }


            int same_item_count = (lug1->item_count == lug2->item_count);

            int similar_weight = (fabs(lug1->total_weight - lug2->total_weight) <= max_weight_diff);

            if (same_item_count && similar_weight) {
                found_pair = 1;


                const char* surname1 = surnames[lug1->passenger_index];
                const char* surname2 = surnames[lug2->passenger_index];

                printf("Found match: \n");
                printf("  - Passenger 1: %s (Items: %d, Weight: %.1f kg)\n",
                       surname1, lug1->item_count, lug1->total_weight);
                printf("  - Passenger 2: %s (Items: %d, Weight: %.1f kg)\n",
                       surname2, lug2->item_count, lug2->total_weight);
                printf("---------------------------------\n");
            }
        }
    }

    return found_pair;
}


void free_surnames(char** surnames, int surname_count) {
    if (surnames == NULL) return;

    for (int i = 0; i < surname_count; ++i) {
        free(surnames[i]);
    }
    free(surnames);
}


void free_luggage(struct Luggage* luggage_list) {
    free(luggage_list);
}