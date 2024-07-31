#include <iostream>

using namespace std;

int readNumber(){

    int number;

    cout<<"N: ";
    cin>>number;

    return number;
}

void powerOf_2_3_4(int number){
    int a, b, c;
    a = number * number;
    b = number * number * number;
    c = number * number * number * number;
    cout<<a<<"\n"<<b<<"\n"<<c<<endl;
}

int main(){

    powerOf_2_3_4(readNumber());

    return 0;
}