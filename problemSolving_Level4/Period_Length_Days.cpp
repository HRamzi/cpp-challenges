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
	cout << "\n  Enter a Day? ";
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
	return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}

short periodLength(stPeriod period, bool IncludeEndDate = false) {
	short days = 0;
	while (IsDate1BeforeDate2(period.startDate, period.endDate)) {
		days++;
		period.startDate = increaseDayByOne(period.startDate);
	}
	return IncludeEndDate ? ++days : days;
}

int main() {

	stPeriod period;

	cout << "\n Enter period :\n";
	period = readPeriod();

	cout << "\nPeriod Length is: " << periodLength(period);
	cout << "\nPeriod Length (Including End Date) is: " << periodLength(period, true);



	cout << endl;

	return 0;
}