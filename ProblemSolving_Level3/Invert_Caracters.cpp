#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char readCaracters() {
	char c;
	cout << "Please Enter a Caracter?\n";
	cin >> c;
	return c;
}

char invertCaracters(char c) {
	return isupper((int)c) ? tolower(c) : toupper(c);
}

int main()
{
	char c = readCaracters();

	cout << "Char after inverting case:\n";
	c = invertCaracters(c);
	cout << c << endl;

	return 0;
}