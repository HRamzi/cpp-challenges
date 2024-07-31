#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string readString() {
	string str;
	cout << "Please Enter Your String?\n";
	getline(cin, str);
	return str;
}

string lowerAllString(string str) {

	for (short i = 0; i < str.length(); i++) {
			str[i] = tolower(str[i]);
	}
	return str;
}
string upperAllString(string str) {

	for (short i = 0; i < str.length(); i++) {
			str[i] = toupper(str[i]);
	}
	return str;
}

int main()
{

	string str = readString();
	string UpperStr, LowerStr;

	cout << "\nString after Upper:\n";
	UpperStr = upperAllString(str);
	cout << UpperStr << endl;

	cout << "\nString after Upper:\n";
	LowerStr = lowerAllString(str);
	cout << LowerStr << endl;

	return 0;
}