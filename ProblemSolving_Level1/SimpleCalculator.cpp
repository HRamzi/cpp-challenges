#include <iostream>
#include <string>

using namespace std;

enum enOperationType{add='+', substract='-', multiply='*', divide='/'};

float readNumber(string Message){

    float number;

    cout<<Message<<endl;
    cin>>number;

    return number;
}

enOperationType readOperationType(){

    char opt = '+';

    cout<<"Please Enter Operation Type ( +, -, *, / )?: ";
    cin>>opt;

    return (enOperationType)opt;
}

float Calculate(float Num1, float Num2, enOperationType opt){

    switch(opt)
    {
        case enOperationType::add:
            return Num1+Num2;
        case enOperationType::substract:
            return Num1-Num2;
        case enOperationType::multiply:
            return Num1*Num2;
        case enOperationType::divide:
            return Num1/Num2;
        default:
            return -1;
    }
}

int main(){

    float Num1 = readNumber("Please Enter the first Number: ");
    float Num2 = readNumber("Please Enter the second Number: ");

    enOperationType optype = readOperationType();

    cout<<endl<<"Result= "<<Calculate(Num1, Num2, optype);

    return 0;
}