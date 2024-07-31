#include <iostream>

using namespace std;

int readN(){
    int n;
    cout<<"N: ";
    cin>>n;
    return n;
}

void printToN(int n){
    for (int i=1; i<=n; i++)
        cout<<i<<endl;
    
}

int main(){

    printToN(readN());

    return 0;
}