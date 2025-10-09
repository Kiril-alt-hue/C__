#pragma once
#include <string>

struct Date {
    int day;
    int month;
    int year;
};

extern bool isLeapYear(int year);
extern int daysInMonth(int month, int year);
extern Date nextDay(const Date& d);
extern Date tomorrow(const Date& d);
extern std::string dayOfWeek(const Date& d);
