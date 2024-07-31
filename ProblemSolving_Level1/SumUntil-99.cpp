#include <iostream>

using namespace std;

int sumUntilMinus99(){
    int sum=0, number=0;
    cout<<"Enter numbers until -99\n";
    while (number != -99){
        sum += number;
        cin>>number;
    }

    return sum;
}

int main(){

    int result = sumUntilMinus99();

    cout<<"Sum of Numbers until -99 is: "<<result<<endl;

    return 0;
}