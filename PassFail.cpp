#include <iostream>

using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

int readMark(){

    int mark;

    cout<<"enter your mark: ";
    cin>>mark;

    return mark;
}

enPassFail checkMark(int mark){
    if(mark>=50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void printResult(int mark){
    if(checkMark(mark)==enPassFail::Pass)
        cout<<"you've Pass";
    else
        cout<<"you've Fail";
}

int main(){

    printResult(readMark());

    return 0;
}