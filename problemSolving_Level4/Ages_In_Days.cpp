#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

struct stDate {
    short day;
    short month;
    short year;
};

// Fonction pour lire le jour
short readDay() {
    short day;
    cout << "\n Entrez un jour: ";
    cin >> day;
    return day;
}

// Fonction pour lire le mois
short readMonth() {
    short month;
    cout << " Entrez un mois: ";
    cin >> month;
    return month;
}

// Fonction pour lire l'ann�e
short readYear() {
    short year;
    cout << " Entrez une ann�e: ";
    cin >> year;
    return year;
}

// Fonction pour lire une date compl�te
stDate readFullDate() {
    stDate date;
    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();
    return date;
}

// Fonction pour obtenir la date syst�me actuelle
stDate getSystemDate() {
    stDate date;
    time_t t = time(0);
    tm* now = localtime(&t);

    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;

    return date;
}

// Fonction pour v�rifier si une ann�e est bissextile
bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Fonction pour obtenir le nombre de jours dans un mois donn� d'une ann�e donn�e
short numberOfDaysInMonth(short month, short year) {
    if (month < 1 || month > 12) return 0;
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
}

// Fonction pour v�rifier si c'est le dernier jour du mois
bool isLastDay(short day, short month, short year) {
    return day == numberOfDaysInMonth(month, year);
}

// Fonction pour v�rifier si c'est le dernier mois de l'ann�e
bool isLastMonth(short month) {
    return month == 12;
}

// Fonction pour augmenter la date d'un jour
stDate increaseDayByOne(stDate date) {
    if (isLastDay(date.day, date.month, date.year)) {
        if (isLastMonth(date.month)) {
            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else {
            date.day = 1;
            date.month++;
        }
    }
    else {
        date.day++;
    }

    return date;
}

// Fonction pour comparer deux dates
bool isDate1LessThanDate2(stDate date1, stDate date2) {
    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

// Fonction pour calculer la diff�rence en jours entre deux dates
short DiffrenceInDate(stDate date1, stDate date2, bool IncludingEndDay = false) {
    int days = 0;
    while (isDate1LessThanDate2(date1, date2)) {
        days++;
        date1 = increaseDayByOne(date1);
    }
    return IncludingEndDay ? ++days : days;
}

int main() {
    stDate Date1 = readFullDate();
    stDate Date2 = getSystemDate();

    cout << "\nVotre �ge est: "
        << DiffrenceInDate(Date1, Date2, true) << " jour(s)";

    cout << endl;

    return 0;
}
