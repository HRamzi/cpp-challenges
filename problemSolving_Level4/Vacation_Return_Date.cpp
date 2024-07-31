#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum enWeekEndDays { Fri = 6, Sat = 7 };

struct stDate {
    short day = 0;
    short month = 0;
    short year = 0;
};

short readYear() {
    short year;
    cout << " Please Enter a year: ";
    cin >> year;
    return year;
}

short readMonth() {
    short month;
    cout << " Please Enter a month? ";
    cin >> month;
    return month;
}

short readDay() {
    short day;
    cout << "\n Please Enter a Day? ";
    cin >> day;
    return day;
}

stDate readFullDate() {
    stDate date;
    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();
    return date;
}



short DayOrder(short year, short month, short day) {
    short a;
    short y, m;
    short d;

    a = ((14 - month) / 12);
    y = year - a;
    m = month + 12 * a - 2;

    d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
}

short DayOrder(stDate date) {
    short a;
    short y, m;
    short d;

    a = ((14 - date.month) / 12);
    y = date.year - a;
    m = date.month + 12 * a - 2;

    d = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
}

short OrdereMonth(short month) {
    string DaysArr[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return (month - 1);
}



string DayName(short day) {
    string DaysArr[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return DaysArr[day];
}

string GetNameDay(stDate date) {
    return DayName(DayOrder(date));
}

bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short numberOfDaysInMonth(short month, short year) {
    if (month < 1 || month>12) return  0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
}

bool isLastDay(short day, short month, short year) {
    return day == numberOfDaysInMonth(month, year);
}

bool isLastMonth(short month) {
    return month == 12;
}

stDate increaseDayByOne(stDate date) {
    if (isLastDay(date.day, date.month, date.year)) {
        if (isLastMonth(date.month)) {
            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else {
            date.day = 1;
            date.month++;
        }
    }
    else {
        date.day++;
    }

    return date;
}

bool isDate1LessThanDate2(stDate date1, stDate date2) {
    return  (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

bool IsBusinessDay(stDate date) {
    return DayOrder(date) < 5;
}

string CalculateVacationReturnDate(stDate DateFrom, short VacationDays) {
    for (int i = 1; i <= VacationDays; i++) {
        if (IsBusinessDay(DateFrom)) {
            DateFrom = increaseDayByOne(DateFrom);
        }
        else {
            --i;
            DateFrom = increaseDayByOne(DateFrom);
        }
    }
    string VacationReturnDate = to_string(DateFrom.day) + "/" + to_string(DateFrom.month) + "/" + to_string(DateFrom.year);

    return GetNameDay(DateFrom) + ", " + VacationReturnDate;
}

int main() {

    cout << "\n Vacation Starts:";
    stDate DateFrom = readFullDate();

    short VacationDays;
    cout << "\n Please Enter vacation days? ";
    cin >> VacationDays;

    cout << "\n\n Return Day is: " << CalculateVacationReturnDate(DateFrom, VacationDays);

    cout << endl;

    return 0;
}