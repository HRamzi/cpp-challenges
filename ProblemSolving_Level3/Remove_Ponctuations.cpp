#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string removePunctuationsFromString(string str) {
    
    string strAfterPunc = "";

    for (int i = 0; i < str.length(); i++) {
        if (!ispunct(str[i])) {
            strAfterPunc += str[i];
        }
    }
    return strAfterPunc;
}

int main() {
    string str = "Welcome to Jordan, Jordan is a nice country; it's an amazing";

    cout << "Original String:\n" << str;

    cout << "\n\nString after Punctuations Removed:";
    cout << "\n" << removePunctuationsFromString(str);

    cout << endl;

    return 0;
}
