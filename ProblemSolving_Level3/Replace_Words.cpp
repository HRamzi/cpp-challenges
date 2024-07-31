#include <iostream>
#include <string>

using namespace std;

string replaceWordInString(string str, string strToReplace, string ReplaceTo) {

	int pos = str.find(strToReplace);
	
	while (pos != std::string::npos) {
		str.replace(pos, strToReplace.length(), ReplaceTo);
		pos = str.find(strToReplace);
	}
	return str;
}

int main()
{

	string str = "Welcome to Jordan, Jordan is a nice country\n";
	string strToReplace = "Jordan";
	string ReplaceTo = "Algeria";

	cout << "Original String\n";
	cout << str;

	cout << "\nString After Replace:\n" << replaceWordInString(str, strToReplace, ReplaceTo);
	cout << endl;

	return 0;
}