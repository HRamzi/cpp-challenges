#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int readNumber(string msg){
    int num; 
    cout<<msg;
    cin>>num;
    return num;
}

int randomNum(int from, int To){
    int randNum = rand() % (To - from + 1) + from;
    return randNum;
}

void fillArrayWithNumbersFrom1toN(int *arr, int arrLength){
    for(int i=0; i<arrLength; i++)
        arr[i] = i+1;
}

void Swap(int &A, int &B){
    int temp;

    temp = A;
    A = B;
    B = temp;
}

void shuffleArray(int *arr, int arrLength){
    int A = arr[randomNum(1, arrLength)-1];
    int B = arr[randomNum(1, arrLength)-1];
    Swap(A, B);
}

void printArray(int *arr, int arrLength){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    srand((unsigned)time(NULL));

    int arrLength = readNumber("Enter the Length of the Arrays: ");

    int arr[100];
    fillArrayWithNumbersFrom1toN(arr, arrLength);

    cout<<"\nArray Elements before shuffle:\n";
    printArray(arr, arrLength);

    shuffleArray(arr, arrLength);

    cout<<"\nArray Elements After shuffle:\n";
    printArray(arr, arrLength);
    cout<<"\n";

    return 0;
}