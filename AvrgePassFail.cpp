#include <iostream>

using namespace std;

enum enPassFail {Pass=1, Fail=2};

void readMarks(int &mark1, int &mark2, int &mark3){
    
    cout<<"Enter three marks: \n";

    cout<<"mark1: ";
    cin>>mark1;

    cout<<"mark2: ";
    cin>>mark2;

    cout<<"mark3: ";
    cin>>mark3;
}

int sumOfMarks(int mark1, int mark2, int mark3){

    return mark1+mark2+mark3;
}

float avrgeOfMarks(int mark1, int mark2, int mark3){

    return (float)sumOfMarks(mark1, mark2, mark3) / 3;

}

enPassFail checkAvrge(float avrge){

    if(avrge >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;

}

void printResult(float avrge){

    cout<<"you're Average is: "<<avrge<<endl;

    if(checkAvrge(avrge)==enPassFail::Pass)
        cout<<"you Passed";
    else
        cout<<"you Failed";

}

int main(){

    int mark1, mark2, mark3;

    readMarks(mark1, mark2, mark3);
    printResult(avrgeOfMarks(mark1, mark2, mark3));

    return 0;
}