#include <iostream>
#include <string>
#include <vector>

using namespace std;

string joinString(vector<string> vectString, string delim) {

	string str;

	for (string& element : vectString) {
		str = str + element + delim;
	}
	return str.substr(0, str.length() - delim.length());
}

string joinString(string arrStr[], int stringLength, string delim) {
	
	string str;

	for (int i = 0; i < stringLength; i++) {
		str = str + arrStr[i] + delim;
	}
	return str.substr(0, str.length() - delim.length());
}

int main() {

	vector<string> vectString = { "Mohammed", "Faid", "Ali", "Maher" };
	cout << "Vector after join:\n\n";
	cout << joinString(vectString, " ");
	cout << endl;

	string arrStr[] = {"Mohammed", "Faid", "Ali", "Maher"};
	cout << "\nArray after join:\n\n";
	cout << joinString(arrStr, 4, " ");
	cout << endl;

	return 0;
}