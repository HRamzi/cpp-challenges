#include <iostream>

using namespace std;

void readNums(int &n1, int &n2){

    cout<<"n1: ";
    cin>>n1;

    cout<<"n2: ";
    cin>>n2;
}

void swapNums(int &n1, int &n2){
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void printResult(int n1, int n2){
    cout<<"after swap:\n";
    cout<<"n1: "<<n1<<"  "<<"n2: "<<n2<<endl;
}

int main(){
    int n1, n2;
    readNums(n1, n2);
    swapNums(n1, n2);
    printResult(n1, n2);

    return 0;
}