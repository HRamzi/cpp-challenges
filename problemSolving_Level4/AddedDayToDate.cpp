#include <iostream>
#include <string>

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

stDate readFullDays() {
	stDate date;
	date.day = readDay();
	date.month = readMonth();
	date.year = readYear();
	return date;
}

short readDaysToAdd() {
	short day;
	cout << "\n Enter number of Days to add? ";
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

stDate DateAddDays(short DaysToAdd, stDate Date) {
	
	short RemainingDay = DaysToAdd + numberOfDayFromBeginningYear(Date.day, Date.month, Date.year);
	short MonthDays;

	while (true) {
		MonthDays = numberOfDaysInMonth(Date.month, Date.year);
		if (RemainingDay > MonthDays) {
			RemainingDay -= MonthDays;
			Date.month++;
			if (Date.month > 12) {
				Date.month = 1;
				Date.year++;
			}
		}
		else {
			Date.day = RemainingDay;
			break;
		}
	}
	return Date;
}

int main() {

	stDate Date = readFullDays();
	short DaysToAdd = readDaysToAdd();

	Date = getDayFromDaysOrderInYear(DaysToAdd, Date);
	cout << "\nDate for [" << DaysToAdd << "] is: ";
	cout << Date.day << "/" << Date.month << "/" << Date.year;

	cout << endl;

	return 0;
}