#include <iostream>
#include <string>

using namespace std;


short readYear() {
	short year;
	cout << "Enter a year: ";
	cin >> year;
	return year;
}

short readMonth() {
	short month;
	cout << "Enter a month? ";
	cin >> month;
	return month;
}

string MonthShortName(short month) {
	string DaysArr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	return DaysArr[month - 1];
}

bool isLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short DayOfweekOrder(short day, short month, short year) {
	short a, y, m;
	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;
	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short numberOfDaysInMonth(short month, short year) {
	if (month < 1 || month>12) return  0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
}

void printMonthCalendar(short month, short year) {

	int numberOfDays;

	int current = DayOfweekOrder(1, month, year);
	numberOfDays = numberOfDaysInMonth(month, year);

	printf("\n __________________%s__________________\n\n",MonthShortName(month).c_str());

	printf("  Sun  Mon  Tue  Wed  thu  Fri  Sat\n");

	int i;
	for (i = 0; i < current; i++) {
		printf("     ");
	}

	int cmpt = 0;
	for (int j = 1; j <= numberOfDays; j++) {
		printf("%5d", j);

		if (++i == 7) {
			i = 0;
			printf("\n");
		}
	}

	printf("\n ____________________________________\n");
}

int main() {

	short year = readYear();
	short month = readMonth();

	printMonthCalendar(month, year);

	return 0;
}