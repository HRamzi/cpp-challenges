#include <iostream>

using namespace std;

struct stDate {
    short day;
    short month;
    short year;
};

struct stPeriod {
    stDate startDate;
    stDate endDate;
};

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

short readYear() {
    short year;
    cout << "  Enter a year: ";
    cin >> year;
    return year;
}

short readMonth() {
    short month;
    cout << "  Enter a month? ";
    cin >> month;
    return month;
}

short readDay() {
    short day;
    cout << "  Enter a Day? ";
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

stPeriod readPeriod() {
    stPeriod Period;
    cout << "\n Enter Start Date:";
    Period.startDate = readFullDate();
    cout << "\n Enter End Date:";
    Period.endDate = readFullDate();
    return Period;
}

bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short numberOfDaysInMonth(short month, short year) {
    if (month < 1 || month > 12) return 0;
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

bool isDate1EqualDate2(stDate Date1, stDate Date2) {
    return ((Date1.year == Date2.year) ? ((Date1.month == Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false) : false);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}

bool isDate1AfterDate2(stDate Date1, stDate Date2) {
    return (!IsDate1BeforeDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2));
}

short periodLength(stPeriod period, bool IncludeEndDate = false) {
    short days = 0;
    while (IsDate1BeforeDate2(period.startDate, period.endDate)) {
        days++;
        period.startDate = increaseDayByOne(period.startDate);
    }
    return IncludeEndDate ? ++days : days;
}

short compareDates(stDate Date1, stDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (isDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

bool isOverlaPeriod(stPeriod period1, stPeriod period2) {
    if (
        compareDates(period2.endDate, period1.startDate) == enDateCompare::Before
        ||
        compareDates(period2.startDate, period1.endDate) == enDateCompare::After
        )
        return false;
    return true;
}

bool isWithinPeriod(stPeriod period, stDate DateToCheck) {
    if (
        compareDates(DateToCheck, period.startDate) != enDateCompare::Before
        &&
        compareDates(DateToCheck, period.endDate) != enDateCompare::After
        )
        return true;
    return false;
}

short CountOverlapDays(stPeriod period1, stPeriod period2) {
    short OverlapDays = 0;

    if (!isOverlaPeriod(period1, period2)) {
        return 0;
    }

    stDate current = period1.startDate;
    while (IsDate1BeforeDate2(current, period1.endDate) || isDate1EqualDate2(current, period1.endDate)) {
        if (isWithinPeriod(period2, current)) {
            OverlapDays++;
        }
        current = increaseDayByOne(current);
    }

    return OverlapDays;
}

int main() {
    stPeriod period1;
    stPeriod period2;

    cout << "\n Enter period 1:\n";
    period1 = readPeriod();

    cout << "\n Enter period 2:\n";
    period2 = readPeriod();

    cout << "\n\n Overlap Days Is: " << CountOverlapDays(period1, period2);

    cout << endl;

    return 0;
}
