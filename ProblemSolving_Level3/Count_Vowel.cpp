#include <iostream>
#include <string>

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

int countVowels(string str) {
	int counter = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isVowel(tolower(str[i])))
			counter++;
	}
	return counter;
}

int main()
{

	string str = readString();

	cout << "\nNumber of vowels is: " << countVowels(str);
	cout << endl;

	return 0;
}