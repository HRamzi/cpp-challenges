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

string lowerFirstLetterOfEachWord(string str) {

	bool isFirstLetter = true;

	for (short i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && isFirstLetter) {
			str[i] = tolower(str[i]);
		}
		isFirstLetter = (str[i] == ' ' ? true : false);
	}
	return str;
}

int main()
{

	string str = readString();
	cout << "\nString after conversion:\n";
	str = lowerFirstLetterOfEachWord(str);
	cout << str << endl;

	return 0;
}