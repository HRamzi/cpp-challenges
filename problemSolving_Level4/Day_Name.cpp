#include <iostream>

using namespace std;

short DayOrder(short year, short month, short day) {
	short a;
	short y, m;
	short d;

	a = ((14 - month) / 12);
	y = year - a;
	m = month + 12 * a - 2;

	d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayName(short day) {
	string DaysArr[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return DaysArr[day];
}

int main() {

	short year;
	short month;
	short day;

	cout << "Enter a Year? ";
	cin >> year;
	cout << "Enter a Month? ";
	cin >> month;
	cout << "Enter a Day? ";
	cin >> day;

	cout << "\nDate: " << day << "/" << month << "/" << year;
	cout << "\nDay Order: " << DayOrder(year, month, day);
	cout << "\nDay Name: " << DayName(DayOrder(year, month, day));

	cout << endl;

	return 0;
}