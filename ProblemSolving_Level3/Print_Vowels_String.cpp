#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string readString() {
	string str;
	cout << "Please Enter Your string:\n";
	getline(cin, str);
	return str;
}

bool isVowel(char char1) {
	return (char1 == 'a') || (char1 == 'e') || (char1 == 'i') || (char1 == 'o') || (char1 == 'u');
}

void printStringVowels(string str) {
	int counter = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isVowel(tolower(str[i])))
			cout << str[i] << setw(3);
	}
}

int main()
{

	string str = readString();

	cout << "\nVowels in string are: ";
	printStringVowels(str);

	cout << endl;

	return 0;
}