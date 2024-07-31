#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int countCaracter(string str, char letter) {

	int Counter = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == letter)
			Counter++;
	}
	return Counter;
}

int main()
{

	string str;
	char letter;

	cout << "Please Enter Your String:\n";
	getline(cin, str);

	cout << "\nPlease Enter a Caracter?\n";
	cin >> letter;

	cout << "Letter \'" << letter << "' Count = " << countCaracter(str, letter);
	cout << endl;

	return 0;
}