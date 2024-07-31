#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

enum enWeekEndOrder{ Fri = 6, Sat = 7 };

struct stDate {
    short day = 0;
    short month = 0;
    short year = 0;
};

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

short DiffrenceInDate(stDate date1, stDate date2, bool IncludingEndDay = false) {

    int days = 0;
    while (isDate1LessThanDate2(date1, date2)) {
        days++;
        date1 = increaseDayByOne(date1);
    }
    return IncludingEndDay ? ++days : days;
}

stDate GetDate(stDate& date) {

    time_t t = time(nullptr);
    tm* now = localtime(&t);

    date.day = now->tm_mday;
    date.month = now->tm_mon + 1;
    date.year = now->tm_year + 1900;

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

bool IsEndOfWeek(stDate date) {
    return DayName(DayOrder(date)) == "Fri" || DayName(DayOrder(date)) == "Sat";
}

bool IsBusinessDay(stDate date) {
    return DayOrder(date) < 5;
}

short daysUntilEndOfWeek(stDate date) {
    return enWeekEndOrder::Fri - DayOrder(date) - 1;
}

short daysUntilEndOfMonth(stDate date) {
    
    stDate EndOfMonthdate;
    EndOfMonthdate.day = numberOfDaysInMonth(date.month, date.year);
    EndOfMonthdate.month = date.month;
    EndOfMonthdate.year = date.year;

    return DiffrenceInDate(date, EndOfMonthdate);
}

short daysUntilEndOfYear(stDate date) {

    stDate EndOfYeardate;
    EndOfYeardate.day = 31;
    EndOfYeardate.month = 12;
    EndOfYeardate.year = date.year;

    return DiffrenceInDate(date, EndOfYeardate);
}

int main() {

    stDate date;
    
    date = GetDate(date);
    string NameDay = GetNameDay(date);
    cout << "\n Today is " << NameDay << ", ";
    cout << date.day << "/" << date.month << "/" << date.year;

    cout << "\n\n Is It a weekend?\n";
    if (IsEndOfWeek(date)) {
        cout << " Yes, It is a weekend!";
    }
    else {
        cout << " No, It is not a weekend!";
    }

    cout << "\n\n Is It a Business Day?\n";
    if (IsBusinessDay(date)) {
        cout << " Yes, It is a Business Day!";
    }
    else {
        cout << " No, It is not a Business Day!";
    }

    cout << "\n\nDays until of week  : " << daysUntilEndOfWeek(date) << " Day(s).\n";
    cout << "Days until of month : " << daysUntilEndOfMonth(date) << " Day(s).\n";
    cout << "Days until of year  : " << daysUntilEndOfYear(date) << " Day(s).";

    cout << endl;

	return 0;
}