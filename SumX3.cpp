#include <iostream>

using namespace std;

void readNumbers(int &Num1, int &Num2, int &Num3){

    cout<<"Enter three numbers: \n";

    cout<<"num1: ";
    cin>>Num1;

    cout<<"num2: ";
    cin>>Num2;

    cout<<"num3: ";
    cin>>Num3;
}

int sumOf3Numbers(int Num1, int Num2, int Num3){

    return Num1+Num2+Num3;
}

void printResult(int total){

    cout<<"The sum of numbers: "<<total<<endl;

}

int main(){

    int Num1, Num2, Num3;

    readNumbers(Num1, Num2, Num3);
    printResult(sumOf3Numbers(Num1, Num2, Num3));

    return 0;
}