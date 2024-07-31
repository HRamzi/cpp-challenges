#include <iostream>

using namespace std;

bool isLeapYear(short year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short numberOfDaysInMonth(short year, short month) {
	if (month <= 1 || month >= 12) return 0;
	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short numberOfHoursInMonth(short year, short month) {
	return numberOfDaysInMonth(year, month) * 24;
}

int numberOfMinutesInMonth(short year, short month) {
	return numberOfHoursInMonth(year, month) * 60;
}

int numberOfSecondsInMonth(short year, short month) {
	return numberOfMinutesInMonth(year, month) * 3600;
}

int main() {

	short year;
	short month;

	cout << "Enter a Year: ";
	cin >> year;

	cout << "Enter a Month: ";
	cin >> month;

	cout << "\nNumber of Days    in Month [" << month << "] is " << numberOfDaysInMonth(year, month);
	cout << "\nNumber of Hours   in Month [" << month << "] is " << numberOfHoursInMonth(year, month);
	cout << "\nNumber of Minutes in Month [" << month << "] is " << numberOfMinutesInMonth(year, month);
	cout << "\nNumber of Seconds in Month [" << month << "] is " << numberOfSecondsInMonth(year, month);

	cout << endl;

	return 0;
}