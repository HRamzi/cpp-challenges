#include <iostream>
#include <string>

using namespace std;

string readString() {
	string str;
	cout << "Please Enter Your String?\n";
	getline(cin, str);
	return str;
}

void printEachWordInString(string str) {
	
	string delim = " ";

	cout << "\nYour String word are: \n\n";
	short pos = 0;
	string sWord;

	while ((pos = str.find(delim)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != " ")
			cout << sWord << endl;
		str.erase(0, pos + delim.length());
	}
	if (str != " ") {
		cout << str << endl;
	}
}

int main()
{

	printEachWordInString(readString());

	return 0;
}