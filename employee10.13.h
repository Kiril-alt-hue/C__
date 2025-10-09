#ifndef EMPLOYEE10_13_H
#define EMPLOYEE10_13_H

#define MAX_EMPLOYEES 50

typedef enum {
    MALE,
    FEMALE
} Gender;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char surname[50];
    char name[50];
    char position[50];
    Gender gender;
    Date birthDate;
} Employee;

void printEmployee(const Employee* emp);

int calculateAge(const Date* birthDate);

void findMostCommonPosition(const Employee employees[], int count);

void findEmployeesWithSameName(const Employee employees[], int count);

void findEmployeesBySurnameInitial(const Employee employees[], int count, char letter);

void findOldestMale(const Employee employees[], int count);

void findYoungerThanAverage(const Employee employees[], int count);

void findPensioners(const Employee employees[], int count);

#endif // EMPLOYEE10_13_H