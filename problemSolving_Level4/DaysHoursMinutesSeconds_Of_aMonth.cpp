#include <iostream>

using namespace std;

bool isLeapYear(short year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short numberOfDaysInMonth(short year, short month) {
	if (month <= 1 || month >= 12)
		return 0;
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	short arr31Days[] = { 1,3,5,7,8,10,12 };
	for (short i = 1; i <= 7; i++) {
		if (arr31Days[i - 1] == month)
			return 31;
	}
	return 30;
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