#include <iostream>

using namespace std;

void readNums(int &num1, int &num2){
    cout<<"num1: ";
    cin>>num1;

    cout<<"num2: ";
    cin>>num2;
}

int maxNum(int num1, int num2){
    if(num1<num2)
        return num2;
    else
        return num1;
}

void printMax(int max){
    cout<<max<<endl;
}

int main(){
    int num1, num2;
    readNums(num1, num2);
    printMax(maxNum(num1, num2));
    return 0;
}