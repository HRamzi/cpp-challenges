#include <iostream>

using namespace std;

bool isLeapYear(short year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short numberOfDaysInYear(short year) {
	return isLeapYear(year) ? 365 : 366;
}

short numberOfHoursInYear(short year) {
	return numberOfDaysInYear(year) * 24;
}

int numberOfMinutesInYear(short year) {
	return numberOfHoursInYear(year) * 60;
}

int numberOfSecondsInYear(short year) {
	return numberOfMinutesInYear(year) * 3600;
}

int main() {

	short year;

	cout << "Enter a Year: ";
	cin >> year;

	cout << "\nNumber of Days    in Year [" << year << "] is " << numberOfDaysInYear(year);
	cout << "\nNumber of Hours   in Year [" << year << "] is " << numberOfHoursInYear(year);
	cout << "\nNumber of Minutes in Year [" << year << "] is " << numberOfMinutesInYear(year);
	cout << "\nNumber of Seconds in Year [" << year << "] is " << numberOfSecondsInYear(year);

	cout << endl;

	return 0;
}