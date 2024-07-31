#include <iostream>

using namespace std;

struct stDate {
	short day;
	short month;
	short year;
};

short readYear() {
	short year;
	cout << " Enter a year: ";
	cin >> year;
	return year;
}

short readMonth() {
	short month;
	cout << " Enter a month? ";
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

void swapDates(stDate& Date1, stDate& Date2) {
	stDate tempDate;
	tempDate.day = Date1.day;
	tempDate.month = Date1.month;
	tempDate.year = Date1.year;

	Date1.day = Date2.day;
	Date1.month = Date2.month;
	Date1.year = Date2.year;

	Date2.day = tempDate.day;
	Date2.month = tempDate.month;
	Date2.year = tempDate.year;
}

bool isDate1LessThanDate2(stDate Date1, stDate Date2) {
	return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}

short negativeDiffrenceInDate(stDate date1, stDate date2, bool IncludingEndDay = false) {

	int Days = 0;
	short SwapflagValue = 1;

	while (!isDate1LessThanDate2(date1, date2)) {
		swapDates(date1, date2);
		SwapflagValue = -1;
	}
	while (isDate1LessThanDate2(date1, date2)) {
		Days++;
		date1 = increaseDayByOne(date1);
	}

	return IncludingEndDay ? ++Days*SwapflagValue : Days*SwapflagValue;
}

int main() {

	stDate Date1 = readFullDate();
	stDate Date2 = readFullDate();

	cout << "\nDiffrence is: " << negativeDiffrenceInDate(Date1, Date2) << " Day(s)";
	cout << "\nDiffrence (Including End Day) is: " << negativeDiffrenceInDate(Date1, Date2, true) << " Day(s)";

	cout << endl;

	return 0;
}