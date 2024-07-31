#include <iostream>
#include <string>
#include <vector>

using namespace std;

string readString() {
	string str;
	cout << "Please Enter your String?\n";
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

string reverseString(string str) {
	
	vector<string> vectString;
	string revStr;

	vectString = splitString(str);

	vector<string>::iterator iter = vectString.end();

	while (iter != vectString.begin()) {
		
		--iter;

		revStr += *iter + " ";
	}

	revStr = revStr.substr(0, revStr.length() - 1);

	return revStr;
}

int main()
{

	string str = readString();

	cout << "\n\nString After reversing word:\n" << reverseString(str);
	cout << endl;

	return 0;
}