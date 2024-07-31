#include <iostream>
#include <string>

using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

bool isPerfectNumber(int num){
    int sum = 0;
    for(int i=1; i<num; i++){
        if(num % i == 0)
            sum += i;
    }
    return sum==num;
}

void printResult(int num){
    for(int i=1; i<=num; i++){
        if(isPerfectNumber(i))
            cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    printResult(readNumber("Enter number: "));

    return 0;
}