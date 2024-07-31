#include <iostream>

using namespace std;

struct stDate {
	short day;
	short month;
	short year;
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

short OrdereMonth(short month) {
	string DaysArr[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return (month - 1);
}

bool isLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short numberOfDaysInMonth(short month, short year) {
	if (month < 1 || month>12) return  0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
}

bool isFirstDay(stDate date) {
	return date.day == 1;
}

bool isFirstMonth(stDate date) {
	return date.month == 1;
}

stDate decreaseDayByOne(stDate date) {
	if (isFirstDay(date)) {
		if (isFirstMonth(date)) {
			date.day = 31;
			date.month = 12;
			date.year--;
		}
		else {
			date.day = numberOfDaysInMonth(date.month-1, date.year);
			date.month--;
		}
	}
	else {
		date.day--;
	}

	return date;
}

stDate decreaseDateByXDays(stDate date, short DaysToSubs) {
	for (int i = 1; i <= DaysToSubs; i++) {
		if (isFirstDay(date)) {
			if (isFirstMonth(date)) {
				date.day = numberOfDaysInMonth(date.month - 1, date.year) - DaysToSubs - 1;
				date.month = 1;
				date.year--;
			}
			else {
				date.day = numberOfDaysInMonth(date.month - 1, date.year) - DaysToSubs - 1;
				date.month--;
			}
		}
		else {
			date.day--;
		}
	}
	return date;
}

stDate decreaseDateByOneWeek(stDate date) {
	for (int i = 1; i <= 7; i++) {
		date = decreaseDayByOne(date);
	}
	return date;
}

stDate decreaseDateByXWeeks(stDate date, short WeeksToSubs) {
	for (int i = 1; i <= WeeksToSubs; i++) {
		date = decreaseDateByOneWeek(date);
	}
	return date;
}

stDate decreaseDateByOneMonth(stDate date) {

	if (isFirstMonth(date)) {
		date.month = 12;
		date.year--;
	}
	else {
		date.month--;
	}

	short numberfDaysMonth = numberOfDaysInMonth(date.month, date.year);
	if (date.day > numberfDaysMonth) {
		date.day = numberfDaysMonth;
	}

	return date;
}

stDate decreaseDateByXMonths(stDate date, short MonthsToSubs) {
	for (int i = 1; i <= MonthsToSubs; i++) {
		date = decreaseDateByOneMonth(date);
	}
	return date;
}

stDate decreaseDateByOneYear(stDate date) {
	date = decreaseDateByXMonths(date, 12);
	return date;
}

stDate decreaseDateByXYears(stDate date, short YearsToSubs) {
	for (int i = 1; i <= YearsToSubs; i++) {
		date = decreaseDateByOneYear(date);
	}
	return date;
}

stDate decreaseDateByXYearsFaster(stDate date, short YearsToSubs) {
	date.year = date.year - YearsToSubs;
	return date;
}

stDate decreaseDateByOneDecade(stDate date) {
	date = decreaseDateByXYearsFaster(date, 10);
	return date;
}

stDate decreaseDateByXDecades(stDate date, short DecadesToAdd) {
	for (int i = 1; i <= DecadesToAdd; i++) {
		date = decreaseDateByXYearsFaster(date, 10);
	}
	return date;
}

stDate decreaseDateByXDecadesFaster(stDate date, short DecadesToAdd) {
	date.year = date.year - 10 * DecadesToAdd;
	return date;
}

stDate decreaseDateByOneCentury(stDate date) {
	date.year = date.year - 100;
	return date;
}

stDate decreaseDateByOneMillennium(stDate date) {
	date.year = date.year - 1000;
	return date;
}


int main() {

	stDate date = readFullDate();

	cout << "\n Date After:\n";

	date = decreaseDayByOne(date);
	cout << "\n 01-Substracting one day is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByXDays(date, 10);
	cout << " 02-Substracting 10 days is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByOneWeek(date);
	cout << " 03-Substracting one week is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByXWeeks(date, 10);
	cout << " 04-Substracting 10 weeks is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByOneMonth(date);
	cout << " 05-Substracting one month is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByXMonths(date, 5);
	cout << " 06-Substracting 5 months is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByOneYear(date);
	cout << " 07-Substracting one year is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByXYears(date, 10);
	cout << " 08-Substracting 10 years is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByXYearsFaster(date, 10);
	cout << " 09-Substracting 10 years (Faster) is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByOneDecade(date);
	cout << " 10-Substracting one Decade is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByXDecades(date, 10);
	cout << " 11-Substracting 10 Decades is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByXDecadesFaster(date, 10);
	cout << " 12-Substracting 10 Decades (Faster) is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByOneCentury(date);
	cout << " 13-Substracting One Century is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = decreaseDateByOneMillennium(date);
	cout << " 14-Substracting One Millennium is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	cout << endl;

	return 0;
}