#include <iostream>

using namespace std;

void readNums(int &A, int &B, int &C){

    cout<<"A: ";
    cin>>A;

    cout<<"B: ";
    cin>>B;

    cout<<"C: ";
    cin>>C;
}

int maxNum(int A, int B, int C){

    if(A>B)
    {
        if(A>C)
            return A;
        else
            return C;
    }

    else
    {
        if(B>C)
            return B;
        else
            return C;
    }
}

void printMax(int max){

    cout<<max<<endl;
}

int main(){

    int A, B, C;

    readNums(A, B, C);
    printMax(maxNum(A, B, C));

    return 0;
}