#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>  // for toupper()

#include "employee10.13.h"

#define MALE_PENSION_AGE 65
#define FEMALE_PENSION_AGE 60

int calculateAge(const Date* birthDate) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    int currentDay = local->tm_mday;
    int currentMonth = local->tm_mon + 1;
    int currentYear = local->tm_year + 1900;

    int age = currentYear - birthDate->year;

    if (currentMonth < birthDate->month || (currentMonth == birthDate->month && currentDay < birthDate->day)) {
        age--;
    }
    return age;
}

void printEmployee(const Employee* emp) {
    printf("Surname: %s, Name: %s, Position: %s, Gender: %s, DOB: %02d-%02d-%d, Age: %d\n",
           emp->surname,
           emp->name,
           emp->position,
           (emp->gender == MALE) ? "Male" : "Female",
           emp->birthDate.day, emp->birthDate.month, emp->birthDate.year,
           calculateAge(&emp->birthDate));
}


// a)
void findMostCommonPosition(const Employee employees[], int count) {
    if (count == 0) return;

    char positions[MAX_EMPLOYEES][50];
    int counts[MAX_EMPLOYEES] = {0};
    int uniqueCount = 0;

    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(employees[i].position, positions[j]) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(positions[uniqueCount], employees[i].position);
            counts[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    int maxCount = 0;
    char mostCommonPosition[50];
    for (int i = 0; i < uniqueCount; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            strcpy(mostCommonPosition, positions[i]);
        }
    }
    printf("Most common position: '%s' (held by %d people).\n", mostCommonPosition, maxCount);
}

// б)
void findEmployeesWithSameName(const Employee employees[], int count) {
    int checked[MAX_EMPLOYEES] = {0};

    for (int i = 0; i < count; i++) {
        if (checked[i]) continue;

        char currentName[50];
        strcpy(currentName, employees[i].name);
        int nameCount = 0;

        for (int j = i; j < count; j++) {
            if (strcmp(employees[j].name, currentName) == 0) {
                nameCount++;
            }
        }

        if (nameCount > 1) {
            printf("Employees with name '%s':\n", currentName);
            for (int j = i; j < count; j++) {
                if (strcmp(employees[j].name, currentName) == 0) {
                    printf("  - ");
                    printEmployee(&employees[j]);
                    checked[j] = 1;
                }
            }
        }
    }
}

// в)
void findEmployeesBySurnameInitial(const Employee employees[], int count, char letter) {
    printf("Employees whose surname starts with '%c':\n", letter);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (toupper(employees[i].surname[0]) == toupper(letter)) {
            printf("  - ");
            printEmployee(&employees[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("  None found.\n");
    }
}

// г)
void findOldestMale(const Employee employees[], int count) {
    const Employee* oldestMale = NULL;
    int maxAge = -1;

    for (int i = 0; i < count; i++) {
        if (employees[i].gender == MALE) {
            int age = calculateAge(&employees[i].birthDate);
            if (age > maxAge) {
                maxAge = age;
                oldestMale = &employees[i];
            }
        }
    }

    if (oldestMale != NULL) {
        printf("Oldest male employee:\n  - ");
        printEmployee(oldestMale);
    } else {
        printf("No male employees found.\n");
    }
}

// д)
void findYoungerThanAverage(const Employee employees[], int count) {
    if (count == 0) return;

    double totalAge = 0;
    for (int i = 0; i < count; i++) {
        totalAge += calculateAge(&employees[i].birthDate);
    }
    double averageAge = totalAge / count;
    printf("Average age in the organization is %.2f years.\n", averageAge);
    printf("Employees younger than average:\n");

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (calculateAge(&employees[i].birthDate) < averageAge) {
            printf("  - ");
            printEmployee(&employees[i]);
            found = 1;
        }
    }
     if (!found) {
        printf("  None found.\n");
    }
}

// е)
void findPensioners(const Employee employees[], int count) {
    printf("Employees of pension age (Male: %d, Female: %d):\n", MALE_PENSION_AGE, FEMALE_PENSION_AGE);
    int found = 0;
    for (int i = 0; i < count; i++) {
        int age = calculateAge(&employees[i].birthDate);
        if ((employees[i].gender == MALE && age >= MALE_PENSION_AGE) ||
            (employees[i].gender == FEMALE && age >= FEMALE_PENSION_AGE)) {
            printf("  - ");
            printEmployee(&employees[i]);
            found = 1;
        }
    }
     if (!found) {
        printf("  None found.\n");
    }
}