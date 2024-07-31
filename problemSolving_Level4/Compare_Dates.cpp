#include <iostream>

using namespace std;

struct stDate {
	short day;
	short month;
	short year;
};

enum enDateCompare{ Before = -1, Equal = 0, After = 1};

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
	return (Date1.year < Date2.year) && (Date1.month < Date2.month) && (Date1.day < Date2.day);
}

bool isDate1AfterDate2(stDate Date1, stDate Date2) {
	return (!isDate1LessThanDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2));
}

short compareDates(stDate Date1, stDate Date2) {
	
	if (isDate1LessThanDate2(Date1, Date2))
		return enDateCompare::Before;

	if (isDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

int main() {

	stDate Date1 = readFullDate();
	cout << "\n" << endl;
	stDate Date2 = readFullDate();

	cout << "\nCompare result = " << compareDates(Date1, Date2);

	cout << endl;

	return 0;
}