#ifndef C___LUGGAGE_PROCESSOR11_11_H
#define C___LUGGAGE_PROCESSOR11_11_H

#include <stdio.h>

#define MAX_LINE_LENGTH 256

struct Luggage {
    int passenger_index; // Індекс пасажира (номер рядка з файлу прізвищ, 0-індексація)
    int item_count;      // Кількість речей
    double total_weight; // Загальна вага
};

char** load_surnames(const char* filename, int* surname_count);


struct Luggage* load_luggage(const char* filename, int* luggage_count);



int find_similar_luggage_passengers(
    char** surnames,
    int surname_count,
    struct Luggage* luggage_list,
    int luggage_count,
    double max_weight_diff
);

void free_surnames(char** surnames, int surname_count);


void free_luggage(struct Luggage* luggage_list);

#endif //C___LUGGAGE_PROCESSOR11_11_H