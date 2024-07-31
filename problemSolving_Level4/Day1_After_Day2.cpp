#include <iostream>

using namespace std;

struct stDate {
	short day;
	short month;
	short year;
};

short readYear() {
	short year;
	cout << "\n Please Enter a year: ";
	cin >> year;
	return year;
}

short readMonth() {
	short month;
	cout << "\n Please Enter a month? ";
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

bool isDate1EqualDate2(stDate Date1, stDate Date2) {
	return ((Date1.year == Date2.year) ? ((Date1.month == Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false) : false);
}

bool isDate1LessThanDate2(stDate Date1, stDate Date2) {
	return (Date1.year <= Date2.year) && (Date1.month <= Date2.month) && (Date1.day <= Date2.day);
}

bool isDate1AfterDate2(stDate Date1, stDate Date2) {
	return (!isDate1LessThanDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2));
}

int main() {

	stDate Date1 = readFullDate();
	cout << "\n" << endl;
	stDate Date2 = readFullDate();

	if (isDate1AfterDate2(Date1, Date2)) {
		cout << "\nYes, Date1 is After Date2";
	}
	else {
		cout << "\nNo, Date1 is not After Date2";
	}

	cout << endl;

	return 0;
}