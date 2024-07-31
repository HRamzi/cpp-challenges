#include <iostream>
using namespace std;

void addArrayElements(int &arrLength, int *arr, int Number){
    arrLength++;
    arr[arrLength-1] = Number;
}

int findNumberPositionInArray(int arrLength, int *arr, int number){
    for(int i=0; i<arrLength; i++){
        if(arr[i] == number)
            return i;
    }
    return -1;
}

bool isNumberInArray(int arrLength, int *arr, int number){
    return findNumberPositionInArray(arrLength, arr, number) != -1;
}

void copyDistinctElements(int arrSourceLength, int &arrDestinationLength, int *arrSource, int *arrDestination){
    for(int i=0; i<arrSourceLength; i++){
        if(!isNumberInArray(arrDestinationLength, arrDestination, arrSource[i]))
                addArrayElements(arrDestinationLength, arrDestination, arrSource[i]);
    }
}

void printArray(int &arrLength, int *arr){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    int arr1Length=10;
    int arr1[] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90};

    cout<<"\nArray 1 elements:\n";
    printArray(arr1Length, arr1);

    int arr2[100], arr2Length = 0;
    copyDistinctElements(arr1Length, arr2Length, arr1, arr2);

    cout<<"\nArray 2 distinct elements:\n";
    printArray(arr2Length, arr2);

    cout<<"\n";

    return 0;
}