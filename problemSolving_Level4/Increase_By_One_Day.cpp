#include <iostream>

using namespace std;

struct stDate {
	short day;
	short month;
	short year;
};

short readYear() {
	short year;
	cout << "\n Enter a year: ";
	cin >> year;
	return year;
}

short readMonth() {
	short month;
	cout << "\n Enter a month? ";
	cin >> month;
	return month;
}

short readDay() {
	short day;
	cout << "\n Enter a Day? ";
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
	if (isLastDay(date. day, date.month, date.year)) {
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

int main() {

	stDate date = readFullDate();

	date = increaseDayByOne(date);

	cout << "\nDate After Adding one day: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	cout << endl;

	return 0;
}