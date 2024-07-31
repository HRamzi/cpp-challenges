#include <iostream>
#include <string>
using namespace std;

string readPassword(){

    string password;

    cout<<"Enter a 3-Letter Password (all Capital)?\n";
    cin>>password;

    return password;
}

bool guessPassword(string password){

    string word = "";
    int cmpt = 0;

    for(char i='A'; i<='Z'; i++){
        for(char j='A'; j<='Z'; j++){
            for(char k='A'; k<='Z'; k++){
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                cmpt++;
                cout<<"Trail["<<cmpt<<"] : "<<word<<endl;
                if(word == password){
                    cout<<"Password is: "<<word<<endl;
                    cout<<"Found after "<<cmpt<<" Trial(s)"<<endl;
                    return true;
                }
                word = "";
            }
        }
    }
    return false;
}

int main(){

    guessPassword(readPassword());

    return 0;
}