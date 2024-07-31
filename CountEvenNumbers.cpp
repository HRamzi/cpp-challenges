#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int readNumber(string msg){
    int number;
    cout<<msg;
    cin>>number;
    return number;
}

int randomNumber(int From, int To){
    int randNumber = rand() % (To - From + 1) + From;
    return randNumber;
}

void fillArrayWithNumbers(int arrLength, int *arr){
    for(int i=0; i<arrLength; i++){
        arr[i] = randomNumber(1, 100);
    }
}

int countEvenNumbers(int arrLength, int *arr){
    int counter = 0;
    for(int i=0; i<arrLength; i++){
        if(arr[i] % 2 != 0)
            counter++;
    }
    return counter;
}

void printArray(int arrLength, int *arr){
    for(int i=0; i<arrLength; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    srand((unsigned)time(NULL));

    int arrLength;
    arrLength = readNumber("\nEnter Number of Array Elements:\n");

    int arr[100];
    fillArrayWithNumbers(arrLength, arr);

    cout<<"\nArray Elements: ";
    printArray(arrLength, arr);

    cout<<"Even number count is: "
        <<countEvenNumbers(arrLength, arr);

    cout<<"\n\n";

    return 0;
}