#include <iostream>

using namespace std;

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

bool isLastDay(short day, short month, short year) {
	return day == numberOfDaysInMonth(month, year);
}

bool isLastMonth(short month) {
	return month == 12;
}

int main() {

	short day = readDay();
	short month = readMonth();
	short year = readYear();

	if (isLastDay(day, month, year)) {
		cout << "\nYes, it is the Last Day!";
	}
	else {
		cout << "\nNo, it is not the Lat Day!";
	}

	if (isLastMonth(month)) {
		cout << "\nYes, it is the Last month!";
	}
	else {
		cout << "\nNo, it is not the Lat month!";
	}

	cout << endl;

	return 0;
}