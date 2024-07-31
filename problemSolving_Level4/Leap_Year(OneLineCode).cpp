#include <iostream>

using namespace std;

bool isLeapYear(short year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main() {

	short year;

	cout << " Enter year: ";
	cin >> year;

	if (isLeapYear(year)) {
		cout << "\nYes, Year [" << year << "] is a leap year\n";
	}
	else {
		cout << "\nNO, Year [" << year << "] is NOT a leap year\n";
	}

	return 0;
}