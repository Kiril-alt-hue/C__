#include <stdio.h>
#include <stdlib.h>
#include "luggage_processor11.11.h"

void create_test_files() {
    FILE* passengers_file = fopen("passengers.txt", "w");
    if (passengers_file != NULL) {
        fprintf(passengers_file, "Petrenko\n"); // Індекс 0
        fprintf(passengers_file, "Ivanenko\n"); // Індекс 1
        fprintf(passengers_file, "Sydorenko\n"); // Індекс 2
        fprintf(passengers_file, "Kovalchuk\n"); // Індекс 3
        fprintf(passengers_file, "Bondarenko\n"); // Індекс 4
        fclose(passengers_file);
    } else {
        fprintf(stderr, "Error: Could not create passengers.txt\n");
    }

    FILE* luggage_file = fopen("luggage.txt", "w");
    if (luggage_file != NULL) {
        // Petrenko (0) та Kovalchuk (3) - мають однакову к-ть речей (3)
        // і різницю у вазі 0.5 кг (15.5 - 15.0)
        fprintf(luggage_file, "0 3 15.5\n"); // Petrenko
        fprintf(luggage_file, "3 3 15.0\n"); // Kovalchuk

        // Ivanenko (1) та Sydorenko (2) - однакова к-ть речей (5),
        // але велика різниця у вазі (25.0 - 20.0 = 5.0 кг)
        fprintf(luggage_file, "1 5 20.0\n"); // Ivanenko
        fprintf(luggage_file, "2 5 25.0\n"); // Sydorenko

        // Bondarenko (4) - немає пари
        fprintf(luggage_file, "4 2 8.1\n"); // Bondarenko
        fclose(luggage_file);
    } else {
        fprintf(stderr, "Error: Could not create luggage.txt\n");
    }
}


int main() {
    create_test_files();

    int surname_count = 0;
    int luggage_count = 0;

    char** surnames = load_surnames("passengers.txt", &surname_count);
    struct Luggage* luggage_list = load_luggage("luggage.txt", &luggage_count);

    if (surnames == NULL || luggage_list == NULL) {
        printf("Failed to load data from files. Exiting.\n");
        if(surnames) free_surnames(surnames, surname_count);
        if(luggage_list) free_luggage(luggage_list);
        return 1;
    }

    double a_kg = 1.0;

    int found = find_similar_luggage_passengers(surnames, surname_count, luggage_list, luggage_count, a_kg);
    if (!found) {
        printf("No passenger pairs found with the given criteria (a = %.1f kg).\n", a_kg);
    }

    printf("\n=== New Search ===\n\n");

    a_kg = 5.0;
    found = find_similar_luggage_passengers(surnames, surname_count, luggage_list, luggage_count, a_kg);
    if (!found) {
        printf("No passenger pairs found with the given criteria (a = %.1f kg).\n", a_kg);
    }

    free_surnames(surnames, surname_count);
    free_luggage(luggage_list);

    return 0;
}