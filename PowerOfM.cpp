#include <iostream>

using namespace std;

int readNumber(){

    int number;

    cout<<"N: ";
    cin>>number;

    return number;
}

int readPower(){

    int M;

    cout<<"M: ";
    cin>>M;

    return M;
}

int powerOfM(int number, int M){

    if(M==0)
        return 1;

    int p=1;
    for(int i=1; i<=M; i++)
        p *= number;

    return p;
}

int main(){

    cout<<powerOfM(readNumber(), readPower());

    return 0;
}