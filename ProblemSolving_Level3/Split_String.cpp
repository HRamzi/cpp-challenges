#include <iostream>
#include <string>
#include <vector>

using namespace std;

string readString() {
	string str;
	cout << "Please Enter Your String?\n";
	getline(cin, str);
	return str;
}

vector<string> splitString(string str) {

	string delim = " ";

	short pos = 0;
	string sWord;

	vector<string> vectWord;

	while ((pos = str.find(delim)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != " ") {
			vectWord.push_back(sWord);
		}
		str.erase(0, pos + delim.length());
	}
	if (str != " ") {
		vectWord.push_back(str);
	}

	return vectWord;
}

int main()
{

	string str = readString();
	vector<string> vectWord;

	vectWord = splitString(str);
	cout << "\nTokens = " << vectWord.size() << "\n\n";
	for (string& element : vectWord)
		cout << element << "\n";

	cout << endl;

	return 0;
}