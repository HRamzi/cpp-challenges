#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum charType {SmallLetter = 1, CapitaLetter = 2, SpecialCharacter = 3, Digit = 4};

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

int randomNum(int from, int To){
    int randNum = rand() % (To - from + 1) + from;
    return randNum;
}

char getRandomCharacter(charType CharType){
    switch(CharType){
        case charType::SmallLetter:
            return (char)randomNum(97, 122);
        case charType::CapitaLetter:
            return (char)randomNum(65, 90);
        case charType::SpecialCharacter:
            return (char)randomNum(33, 47);
        case charType::Digit:
            return (char)randomNum(48, 57);
        default:
            break;
    }
}

string getWord(charType CharType, short length){
    string word="";
    for(int i=1; i<=length; i++){
        word += getRandomCharacter(CharType);
    }
    return word;
}

string getKey(){
    string key="";
    key = getWord(charType::CapitaLetter, 4) + "-";
    key += getWord(charType::CapitaLetter, 4) + "-";
    key += getWord(charType::CapitaLetter, 4) + "-";
    key += getWord(charType::CapitaLetter, 4);
    return key;
}

void generateKeys(short numberKeys){
    for(int i=1; i<=numberKeys; i++){
        cout<<"Key["<<i<<"] : ";
        cout<<getKey()<<endl;
    }
}

int main(){

    srand((unsigned)time(NULL));

    generateKeys(readNumber("Enter number of keys to generate:\n"));

    return 0;
}