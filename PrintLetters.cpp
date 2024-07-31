#include <iostream>

using namespace std;

void printLetters(char from, char To){
    for(char i=from; i<=To; i++){
        cout<<i<<endl;
    }
}

int main(){

    printLetters('A','a');

    return 0;
}