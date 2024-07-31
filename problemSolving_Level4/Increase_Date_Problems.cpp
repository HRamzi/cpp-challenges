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

bool isLastDay(stDate date) {
	return date.day == numberOfDaysInMonth(date.month, date.year);
}

bool isLastMonth(stDate date) {
	return date.month == 12;
}

stDate increaseDayByOne(stDate date) {
	if (isLastDay(date)) {
		if (isLastMonth(date)) {
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

stDate increaseDateByXDays(stDate date, short DaysToAdd) {
	for (int i = 1; i <= DaysToAdd; i++) {
		if (isLastDay(date)) {
			if (isLastMonth(date)) {
				date.day = DaysToAdd - i;
				date.month = 1;
				date.year++;
				return date;
			}
			else {
				date.day = DaysToAdd - i;
				date.month++;
				return date;
			}
		}
		else {
			date.day++;
		}
	}
	return date;
}

stDate increaseDateByOneWeek(stDate date) {
	return increaseDateByXDays(date, 7);
}

stDate increaseDateByXWeeks(stDate date, short WeeksToAdd) {
	for (int i = 1; i <= WeeksToAdd; i++) {
		if ((i > 4) && (i % 4 == 0)) {
			date.day = 01;
			date = increaseDateByOneWeek(date);
		}

		date = increaseDateByOneWeek(date);
	}
	return date;
}

stDate increaseDateByOneMonth(stDate date) {
	
	if (isLastMonth(date)) {
		date.month = 1;
		date.year = date.year++;
	}
	else {
		date.month = date.month++;
	}

	return date;
}

stDate increaseDateByXMonths(stDate date, short MonthsToAdd) {
	for (int i = 1; i <= MonthsToAdd; i++) {
		if (OrdereMonth(date.month) <= 12) {
			date = increaseDateByOneMonth(date);
		}
		else {
			date.month = 1;
			date = increaseDateByOneMonth(date);
		}
	}
	return date;
}

stDate increaseDateByOneYear(stDate date) {
	date = increaseDateByXMonths(date, 12);
	return date;
}

stDate increaseDateByXYears(stDate date, short YearsToAdd) {
	for (int i = 1; i <= YearsToAdd; i++) {
		date = increaseDateByOneYear(date);
	}
	return date;
}

stDate increaseDateByXYearsFaster(stDate date, short YearsToAdd) {
	date.year = date.year + YearsToAdd;
	return date;
}

stDate increaseDateByOneDecade(stDate date) {
	date = increaseDateByXYearsFaster(date, 10);
	return date;
}

stDate increaseDateByXDecades(stDate date, short DecadesToAdd) {
	for (int i = 1; i <= DecadesToAdd; i++) {
		date = increaseDateByXYearsFaster(date, 10);
	}
	return date;
}

stDate increaseDateByXDecadesFaster(stDate date, short DecadesToAdd) {
	date.year = date.year + 10 * DecadesToAdd;
	return date;
}

stDate increaseDateByOneCentury(stDate date) {
	date.year = date.year + 100;
	return date;
}

stDate increaseDateByOneMillennium(stDate date) {
	date.year = date.year + 1000;
	return date;
}


int main() {

	stDate date = readFullDate();

	cout << "\n Date After:\n";

	date = increaseDayByOne(date);
	cout << "\n 01-Adding one day is: ";
	cout << date.day << "/" << date.month << "/" << date.year<<"\n";

	date = increaseDateByXDays(date, 10);
	cout << " 02-Adding 10 days is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByOneWeek(date);
	cout << " 03-Adding one week is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByXWeeks(date, 10);
	cout << " 04-Adding 10 weeks is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByOneMonth(date);
	cout << " 05-Adding one month is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByXMonths(date, 5);
	cout << " 06-Adding 5 months is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByOneYear(date);
	cout << " 07-Adding one year is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByXYears(date, 10);
	cout << " 08-Adding 10 years is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByXYearsFaster(date, 10);
	cout << " 09-Adding 10 years (Faster) is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByOneDecade(date);
	cout << " 10-Adding one Decade is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByXDecades(date, 10);
	cout << " 11-Adding 10 Decades is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByXDecadesFaster(date, 10);
	cout << " 12-Adding 10 Decades (Faster) is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByOneCentury(date);
	cout << " 13-Adding One Century is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	date = increaseDateByOneMillennium(date);
	cout << " 14-Adding One Millennium is: ";
	cout << date.day << "/" << date.month << "/" << date.year << "\n";

	cout << endl;

	return 0;
}