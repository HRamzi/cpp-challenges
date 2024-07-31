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

bool isValidDate(stDate date) {
    return (date.month <= 12) && (date.day <= numberOfDaysInMonth(date.month, date.year));
}

int main() {

	stDate date = readFullDate();

	if (isValidDate(date)) {
		cout << "\n Yes, Date is valide date";
	}
	else
	{
		cout << "\n No, is not a valide date";
	}

	cout << endl;

	return 0;
}