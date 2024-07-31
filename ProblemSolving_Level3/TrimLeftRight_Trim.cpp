#include <iostream>
#include <string>
#include <vector>

using namespace std;

string trimLeft(string str) {
	string str1;
	for (short i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			return str.substr(i, str.length() - i);
		}
	}
	return "";
}

string trimRight(string str) {
	string str1;
	for (short i = str.length() - 1; i >= 0; i--) {
		if (str[i] != ' ') {
			return str.substr(0, i+1);
		}
	}
	return "";
}

string trim(string str) {
	return trimLeft(trimRight(str));
}

int main()
{

	string str = "    Mohammed Abu-Hadhoud		";

	cout << "String = " << str;

	cout << "\n\nTrim Left = " << trimLeft(str) << "\n";
	cout << "\nTrim Right = " << trimRight(str) << "\n";
	cout << "\nTrim = " << trim(str) << "\n";

	return 0;
}