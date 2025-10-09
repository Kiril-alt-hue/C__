#include <iostream>
#include "date10.3.h"
using namespace std;

int main() {
    Date today;

    cout << "Enter today's date (day month year): ";
    cin >> today.day >> today.month >> today.year;

    cout << "\n--- DATE INFORMATION ---\n";

    cout << "Entered date: " << today.day << "/" << today.month << "/" << today.year << endl;
    cout << "Leap year: " << (isLeapYear(today.year) ? "Yes" : "No") << endl;
    cout << "Days in this month: " << daysInMonth(today.month, today.year) << endl;
    cout << "Day of the week: " << dayOfWeek(today) << endl;

    Date tomorrowDate = tomorrow(today);
    cout << "Tomorrow's date: "
         << tomorrowDate.day << "/" << tomorrowDate.month << "/" << tomorrowDate.year << endl;

    cout << "Day of the week tomorrow: " << dayOfWeek(tomorrowDate) << endl;

    return 0;
}
