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

char invertLetterCase(char char1) {
	return isupper((int)char1) ? tolower(char1) : toupper(char1);
}

string invertAllCaracters(string str) {

	for (int i = 0; i < str.length(); i++) {
		str[i] = invertLetterCase(str[i]);
	}
	return str;
}

int main()
{

	string str = readString();
	cout << "\nString after inverting all letter case:\n";
	str = invertAllCaracters(str);
	cout << str << endl;

	return 0;
}