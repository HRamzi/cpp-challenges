#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum enWhatToCount {SmallLetters = 0, CapitalLetters = 1, All = 2};

string readString() {
	string str;
	cout << "Please Enter Your String?\n";
	getline(cin, str);
	return str;
}

int countLetters(string str, enWhatToCount whatToCount=enWhatToCount::All) {

	if (whatToCount == enWhatToCount::All) {
		return str.length();
	}

	int Counter = 0;

	for (int i = 0; i < str.length(); i++) {
		if (whatToCount == enWhatToCount::CapitalLetters && isupper(str[i]))
			Counter++;
		if (whatToCount == enWhatToCount::SmallLetters && islower(str[i]))
			Counter++;
	}
	return Counter;
}

int main()
{

	string str = readString();

	cout << "\nString Length = " << countLetters(str);
	cout << "\nCapital Letters Count = " << countLetters(str, enWhatToCount::CapitalLetters);
	cout << "\nSmall letters Count = " << countLetters(str, enWhatToCount::SmallLetters);
	cout << endl;

	return 0;
}