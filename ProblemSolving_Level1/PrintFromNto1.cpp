#include <iostream>

using namespace std;

int readNumber(){

    int N;

    cout<<"N: ";
    cin>>N;

    return N;
}

void printRangeFrom1toN(int N){

    for (int i=N; i>=1; i--)
        cout<<i<<endl;

}

int main(){

    int N = readNumber();

    printRangeFrom1toN(N);

    return 0;
}