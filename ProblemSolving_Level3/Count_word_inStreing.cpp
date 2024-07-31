#include <iostream>
#include <string>

using namespace std;

string readString() {
	string str;
	cout << "Please Enter Your String?\n";
	getline(cin, str);
	return str;
}

int counthWordInString(string str) {

	int counter = 0;
	string delim = " ";

	short pos = 0;
	string sWord;

	while ((pos = str.find(delim)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != " ")
			counter++;
		str.erase(0, pos + delim.length());
	}
	if (str != " ") {
		counter++;
	}
	return counter;
}

int main()
{

	string str = readString();

	cout << "\nThe number of words in your string is: " << counthWordInString(str);
	cout << endl;

	return 0;
}