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
	return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}

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

bool isWithinPeriod(stPeriod period, stDate DateToCheck) {
	if (
		compareDates(DateToCheck, period.startDate) == enDateCompare::After
		&&
		compareDates(DateToCheck, period.endDate) == enDateCompare::Before
		)
		return true;
	return false;
}

int main() {

	stPeriod period;
	stDate DateToCheck;

	cout << "\n Enter period:\n";
	period = readPeriod();

	cout << "\n Enter Date to Check:\n";
	DateToCheck = readFullDate();

	if (isWithinPeriod(period, DateToCheck)) {
		cout << "\n Yes!, Date is within the period";
	}
	else {
		cout << "\n No!, Date is not within the period";
	}

	cout << endl;

	return 0;
}