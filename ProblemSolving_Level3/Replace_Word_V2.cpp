#include <iostream>
#include <string>
#include <vector>

using namespace std;

string lowerAllString(string str) {
    for (short i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

string joinString(const vector<string>& vectString, const string& delim) {
    string str;
    for (const string& element : vectString) {
        str += element + delim;
    }
    return str.substr(0, str.length() - delim.length());
}

vector<string> splitString(string str, const string& delim) {
    short pos = 0;
    string sWord;
    vector<string> vectWord;

    while ((pos = str.find(delim)) != string::npos) {
        sWord = str.substr(0, pos);
        if (!sWord.empty()) {
            vectWord.push_back(sWord);
        }
        str.erase(0, pos + delim.length());
    }
    if (!str.empty()) {
        vectWord.push_back(str);
    }

    return vectWord;
}

string replaceWordInString(string str, string strToReplace, string sReplaceTo, bool matchCase = true) {

    vector<string> vectString = splitString(str, " ");

    for (string& element : vectString) {
        if (matchCase) {
            if (element == strToReplace) {
                element = sReplaceTo;
            }
        }
        else {
            if (lowerAllString(element) == lowerAllString(strToReplace)) {
                element = sReplaceTo;
            }
        }
    }

    return joinString(vectString, " ");
}

int main() {
    string str = "Welcome to Jordan, Jordan is a nice country";
    string strToReplace = "jordan";
    string replaceTo = "ALGERIA";

    cout << "Original String:\n" << str;

    cout << "\n\nReplace with match case:";
    cout << "\n" << replaceWordInString(str, strToReplace, replaceTo);

    cout << "\n\nReplace without match case:";
    cout << "\n" << replaceWordInString(str, strToReplace, replaceTo, false);

    cout << endl;

    return 0;
}
