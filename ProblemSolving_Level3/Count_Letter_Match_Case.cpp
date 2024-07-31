#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int countCaracter(string str, char letter, bool MatchCase = true) {

    int counter = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (MatchCase) {
            if (str[i] == letter) {
                counter++;
            }
        }
        else {
            if (tolower(str[i]) == tolower(letter)) {
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    string str;
    char letter;

    cout << "Please Enter Your String:\n";
    getline(cin, str);

    cout << "\nPlease Enter a Character:\n";
    cin >> letter;

    cout << "\nLetter \'" << letter << "' Count = " << countCaracter(str, letter);
    cout << "\nLetter \'" << letter << "' Or \'" << (char)toupper(letter) << "'   Count = " << countCaracter(str, letter, false);

    cout << endl;

    return 0;
}
