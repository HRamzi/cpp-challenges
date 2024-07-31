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
    if(isPerfectNumber(num))
        cout<<num<<" "<<"is Perfect"<<endl;
    else
        cout<<num<<" "<<"is Not Perfect"<<endl;
}

int main(){
    printResult(readNumber("Enter number: "));
    return 0;
}