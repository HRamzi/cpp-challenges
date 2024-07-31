#include <iostream>
#include <cstdlib>
using namespace std;

enum charType {SmallLetter = 1, CapitaLetter = 2, SpecialCharacter = 3, Digit = 4};

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

int main(){

    srand((unsigned)time(NULL));

    cout<<getRandomCharacter(charType::SmallLetter)<<endl;
    cout<<getRandomCharacter(charType::CapitaLetter)<<endl;
    cout<<getRandomCharacter(charType::SpecialCharacter)<<endl;
    cout<<getRandomCharacter(charType::Digit)<<endl;

    return 0;
}