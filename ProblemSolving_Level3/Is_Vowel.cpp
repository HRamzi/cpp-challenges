#include <iostream>

using namespace std;

char readCaracter() {
	char char1;
	cout << "Please Enter a caracter:\n";
	cin >> char1;
	return char1;
}

bool isVowel(char char1) {
	return (char1 == 'a') || (char1 == 'e') || (char1 == 'i') || (char1 == 'o') || (char1 == 'u');
}

int main()
{
	char char1;

	char1 = readCaracter();

	if (isVowel(char1)) {
		cout << "\nYes, Letter \'" << char1 << "\' is vowel" << endl;
	}
	else {
		cout << "\nNo, Letter \'" << char1 << "\' is NOT vowel" << endl;
	}


}