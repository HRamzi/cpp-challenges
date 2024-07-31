#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct stDate{
	int day;
	int month;
	int year;
};

vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}

stDate StringToDate(string date, string Separator = "/") {
    stDate Date;
    vector<string> vectDate;
    vectDate = SplitString(date, Separator);
    Date.day = stoi(vectDate[0]);
    Date.month = stoi(vectDate[1]);
    Date.year = stoi(vectDate[2]);

    return Date;
}

string DateToString(stDate Date, string Separator = "/") {
    string date = "";
    
    date += to_string(Date.day) + Separator;
    date += to_string(Date.month) + Separator;
    date += to_string(Date.year);


    return date;
}

string readDate() {
	string date;
	cout << "Please Enter Date dd/mm/yyyy? ";
	cin >> date;
	return date;
}

int main() {

	stDate date = StringToDate(readDate());

    cout << "\nDay: " << date.day << "\n";
    cout << "Month: " << date.month << "\n";
    cout << "year: " << date.year << "\n";

	cout << "\nYou Entered: " << DateToString(date);

    cout << endl;

	return 0;
}