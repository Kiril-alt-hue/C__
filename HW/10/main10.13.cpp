#include <stdio.h>
#include "employee10.13.h"

int main() {
    const int N = 7;
    Employee company[N] = {
        {"Petrenko", "Ivan", "Developer", MALE, {15, 5, 1990}},
        {"Kovalenko", "Anna", "Manager", FEMALE, {22, 8, 1985}},
        {"Ivanenko", "Petro", "Developer", MALE, {3, 11, 1992}},
        {"Sydorenko", "Olena", "Designer", FEMALE, {10, 1, 1995}},
        {"Melnyk", "Ivan", "Manager", MALE, {5, 7, 1960}},
        {"Shevchenko", "Oksana", "Accountant", FEMALE, {30, 12, 1963}},
        {"Bondarenko", "Serhiy", "Developer", MALE, {1, 2, 1958}}
    };

    printf("--- List of all employees ---\n");
    for(int i = 0; i < N; i++) {
        printEmployee(&company[i]);
    }
    printf("\n============================================\n\n");

    printf("a) Find the most common position:\n");
    findMostCommonPosition(company, N);
    printf("\n--------------------------------------------\n\n");

    printf("b) Find employees with the same names:\n");
    findEmployeesWithSameName(company, N);
    printf("\n--------------------------------------------\n\n");

    printf("c) Find employees whose surname starts with 'S':\n");
    findEmployeesBySurnameInitial(company, N, 'S');
    printf("\n--------------------------------------------\n\n");

    printf("d) Find the oldest male employee:\n");
    findOldestMale(company, N);
    printf("\n--------------------------------------------\n\n");

    printf("e) Find employees younger than the average age:\n");
    findYoungerThanAverage(company, N);
    printf("\n--------------------------------------------\n\n");

    printf("f) Find employees of pension age:\n");
    findPensioners(company, N);
    printf("\n============================================\n");

    return 0;
}