#include <iostream>
#include <cmath>

using namespace std;

enum enPrimeNotPrime{Prime = 1, NotPrime = 2};

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

enPrimeNotPrime checkPrime(int num){
    int i = round(num/2);
    for(int count=2; count<=i; count++){
        if(num % count == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

void printAllPrimeNumbers(int num){
    for(int i=1; i<=num; i++){
        if(checkPrime(i) == enPrimeNotPrime::Prime)
            cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    printAllPrimeNumbers(readNumber("Enter Number: "));

    return 0;
}