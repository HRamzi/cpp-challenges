#include <iostream>
#include <string>
using namespace std;

void printAllWords(){
    for(char i='A'; i<='Z'; i++){
        for(char j='A'; j<='Z'; j++){
            for(char k='A'; k<='Z'; k++)
                cout<<i<<j<<k<<endl;
        }
    }
}

int main(){

    printAllWords();

    return 0;
}