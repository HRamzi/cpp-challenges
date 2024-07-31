#include <iostream>
#include <string>
#include <math.h>

using namespace std;

enum enPrimeNotPrime{Prime=1, NotPrime=2};

float readPositiveNumbers(string Message){

    float number;

    do
    {
        cout<<Message<<endl;
        cin>>number;
    } while (number<=0);
    

    return number;
}

enPrimeNotPrime checkPrime(int number){

    int M = round(number/2);

    for(int i=2; i<=M; i++){
        if(number%i==0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
}

void printNumberType(int number){
    if(checkPrime(number)==enPrimeNotPrime::Prime)
        cout<<"--> The Number is Prime";
    else
        cout<<"--> The Number is Not Prime";
}

int main(){

    printNumberType(readPositiveNumbers("Enter a positive Number"));

    return 0;
}