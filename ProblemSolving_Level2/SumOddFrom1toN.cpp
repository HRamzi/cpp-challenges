#include <iostream>

using namespace std;

enum enOddEven{odd=1, even=2};

int readNumber(){

    int number;

    cout<<"N: ";
    cin>>number;

    return number;
}

enOddEven checkOddEven(int number){

    if(number%2!=0)
        return enOddEven::odd;
    else
        return enOddEven::even;

}

int SumOddNumbersFrom1toN(int number){

    int sum=0;

    for(int i=1; i<=number; i++){
        if(checkOddEven(i)==enOddEven::odd)
            sum+=i;
    }

    return sum;

}


int main(){

    cout<<SumOddNumbersFrom1toN(readNumber());

    return 0;
}