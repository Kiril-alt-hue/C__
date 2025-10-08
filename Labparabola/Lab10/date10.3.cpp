#include "date10.3.h"
#include <string>
using namespace std;


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

Date nextDay(const Date& d) {
    Date next = d;
    next.day++;

    if (next.day > daysInMonth(next.month, next.year)) {
        next.day = 1;
        next.month++;
        if (next.month > 12) {
            next.month = 1;
            next.year++;
        }
    }
    return next;
}

Date tomorrow(const Date& d) {
    return nextDay(d);
}

string dayOfWeek(const Date& d) {
    int q = d.day;
    int m = d.month;
    int y = d.year;

    if (m == 1) { m = 13; y--; }
    if (m == 2) { m = 14; y--; }

    int h = (q + (13 * (m + 1)) / 5 + y + y / 4 - y / 100 + y / 400) % 7;

    switch (h) {
        case 0: return "Saturday";
        case 1: return "Sunday";
        case 2: return "Monday";
        case 3: return "Tuesday";
        case 4: return "Wednesday";
        case 5: return "Thursday";
        case 6: return "Friday";
        default: return "";
    }
}
