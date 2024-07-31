#include <iostream>
#include <string>

using namespace std;

string readString() {
	string str;
	cout << "Please Enter Your String?\n";
	getline(cin, str);
	return str;
}

void printFirstLetterOfEachWord(string str) {

	bool isFirstLetter = true;

	cout << "\nFirst Letter of this String:\n";
	
	for (short i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && isFirstLetter) {
			cout << str[i] << endl;
		}
		isFirstLetter = (str[i] == ' ' ? true : false);
	}
}

int main()
{
	printFirstLetterOfEachWord(readString());

	return 0;
}