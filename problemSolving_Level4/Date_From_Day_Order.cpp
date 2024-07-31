#include <iostream>
#include <string>

using namespace std;

struct stDay {
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

bool isLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}



short numberOfDaysInMonth(short month, short year) {
	if (month < 1 || month>12) return  0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
}

short numberOfDayFromBeginningYear(short day, short month, short year) {
	short TotalDays = 0;
	for (int i = 1; i < month; i++) {
		TotalDays += numberOfDaysInMonth(i, year);
	}
	TotalDays += day;

	return TotalDays;
}

stDay getDayFromDaysOrderInYear(short TotalDays, short year) {
	stDay Date;
	short RemainingDay = TotalDays;
	short MonthDays = 0;

	Date.year = year;
	Date.month = 1;

	while (true) {
		MonthDays = numberOfDaysInMonth(Date.month, year);
		if (RemainingDay > MonthDays) {
			RemainingDay -= MonthDays;
			Date.month++;
		}
		else {
			Date.day = RemainingDay;
			break;
		}
	}
	return Date;
}

int main() {

	short day = readDay();
	short month = readMonth();
	short year = readYear();

	short TotalDay = numberOfDayFromBeginningYear(day, month, year);
	cout << "\n\nThe Number of Days From the beginning of the year: ";
	cout << TotalDay;

	stDay Day;
	Day = getDayFromDaysOrderInYear(TotalDay, year);
	cout << "\nDate for [" << TotalDay << "] is: ";
	cout << Day.day << "/" << Day.month << "/" << Day.year;

	cout << endl;

	return 0;
}