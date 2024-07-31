#include <iostream>

using namespace std;

string readName(){
    string name;
    cout<<"enter your name: ";
    getline(cin, name);
    return name;
}

void printName(string name){
    cout<<"\nyour name is: "<<name<<endl;
}

int main(){
    printName(readName());
    return 0;
}
