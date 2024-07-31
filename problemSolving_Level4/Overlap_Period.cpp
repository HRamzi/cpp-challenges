#include <iostream>

using namespace std;

struct stDate {
	short day;
	short month;
	short year;
};

struct stPeriod {
	stDate startDate;
	stDate endDate;
};

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

short readYear() {
	short year;
	cout << "  Enter a year: ";
	cin >> year;
	return year;
}

short readMonth() {
	short month;
	cout << "  Enter a month? ";
	cin >> month;
	return month;
}

short readDay() {
	short day;
	cout << "\n  Enter a Day? ";
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

stPeriod readPeriod() {
	stPeriod Period;
	cout << "\n Enter Start Date:";
	Period.startDate = readFullDate();
	cout << "\n Enter End Date:";
	Period.endDate = readFullDate();
	return Period;
}

bool isDate1EqualDate2(stDate Date1, stDate Date2) {
	return ((Date1.year == Date2.year) ? ((Date1.month == Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false) : false);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
	return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false); }

bool isDate1AfterDate2(stDate Date1, stDate Date2) {
	return (!IsDate1BeforeDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2));
}

short compareDates(stDate Date1, stDate Date2) {

	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (isDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

bool isOverlaPeriod(stPeriod period1, stPeriod period2) {
	if (
		compareDates(period2.endDate, period1.startDate) == enDateCompare::Before
		||
		compareDates(period2.startDate, period1.endDate) == enDateCompare::After
		)
		return false;
	return true;
}

int main() {

	stPeriod period1;
	stPeriod period2;

	cout << "\n Enter period 1:\n";
	period1 = readPeriod();

	cout << "\n Enter period 2:\n";
	period2 = readPeriod();

	if (isOverlaPeriod(period1, period2)) {
		cout << "\n Yes!, Periods Overlap";
	}
	else {
		cout << "\n No!, Periods Does not Overlap";
	}

	cout << endl;

	return 0;
}