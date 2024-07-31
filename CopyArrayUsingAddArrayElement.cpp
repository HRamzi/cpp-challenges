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

void fillArrayWithRandomNumbers(int &arrLength, int *arr){
    for(int i=0; i<arrLength; i++){
        arr[i] = randomNum(1, 100);
    }
}

void printArray(int &arrLength, int *arr){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void addArrayElements(int &arrLength, int *arr, int Number){
    arr[arrLength] = Number;
}

void copyElementsUsing_addArrayElements(int arrLength, int *arrSource, int *arrDestination){
    for(int i=0; i<arrLength; i++)
        addArrayElements(i, arrDestination, arrSource[i]);
}

int main(){

    srand((unsigned)time(NULL));

    int arrLength;
    arrLength = readNumber("Enter number of Array Elements: \n");

    int arr1[100];
    fillArrayWithRandomNumbers(arrLength, arr1);

    cout<<"\nArray 1 elements:\n";
    printArray(arrLength, arr1);

    int arr2[100];
    copyElementsUsing_addArrayElements(arrLength, arr1, arr2);

    cout<<"\nArray 2 elements after copy:\n";
    printArray(arrLength, arr2);

    cout<<"\n";

    return 0;
}