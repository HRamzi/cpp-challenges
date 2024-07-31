#include <iostream>
#include <string>

using namespace std;

int readPositiveNumber(string Message){

    int number;

    do
    {
        cout<<Message<<endl;
        cin>>number;
    
    } while (number);

    return number;
}

int factorial(int number){

    int Fact = 1;

    for(int i=1; i<=number; i++)
        Fact *= i;

    return Fact;
}

int main(){

    cout<<factorial(readPositiveNumber("Enter N: "));

    return 0;
}