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

void fillArrayWithRandomNumbers(int arrLength, int *arr){
    for(int i=0; i<arrLength; i++){
        arr[i] = randomNum(1, 100);
    }
}

void printArray(int arrLength, int *arr){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int findNumberPositionInArray(int arrLength, int *arr, int Number){
    for(int i=0; i<arrLength; i++){
        if(arr[i] == Number)
            return i;
    }
    return -1;
}

bool isNumberInArray(int arrLength, int *arr, int Number){
    return findNumberPositionInArray(arrLength, arr, Number) != -1;
}

int main(){

    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    arrLength = readNumber("\nEnter Number of Elments: ");
    fillArrayWithRandomNumbers(arrLength, arr);

    cout<<"\nArray Elements:\n";
    printArray(arrLength, arr);

    int Number = readNumber("\nEnter a number to search for:\n");
    cout<<"\nNumber you are looking for is: "<<Number<<endl;

    if(!isNumberInArray(arrLength, arr, Number))
        cout<<"\nNo, The Number isn\'t Find :-(\n\n";
    else
        cout<<"\nYes, The Number is Found :-)\n\n";

    return 0;
}