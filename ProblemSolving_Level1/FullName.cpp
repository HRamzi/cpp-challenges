#include <iostream>
#include <string.h>

using namespace std;

struct stInfo{

    string FirstName;
    string LastName;
};

stInfo readFullName(){

    stInfo Info;

    cout<<"Enter your First name: ";
    cin>>Info.FirstName;

    cout<<"Enter your Last name: ";
    cin>>Info.LastName;

    return Info;
}

string getFullName(stInfo Info){

    string FullName = Info.FirstName+" "+Info.LastName;

    return FullName;
}

void printFullName(string FullName){

    cout<<"\n your full name is: "<<FullName<<"\n";
}

int main(){

    printFullName(getFullName(readFullName()));

    return 0;
}