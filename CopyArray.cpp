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

void printArray(int *arr, int arrLength){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

void fillArrayWithRandomNumbers(int *arr, int &arrLength){
    for(int i=0; i<arrLength; i++){
        arr[i] = randomNum(1, 100);
    }
}

void copyArrayElements(int arrLength, int *arrSource, int *arrDestionation){
    for(int i=0; i<arrLength; i++){
        arrDestionation[i] = arrSource[i];
    }
}

int main(){

    srand((unsigned)time(NULL));
    int arr1[100], arr2[100];
    int arrLength;

    arrLength = readNumber("\nEnter a Number: ");

    fillArrayWithRandomNumbers(arr1, arrLength);

    cout<<"\nArray1 Elements:\n";
    printArray(arr1, arrLength);
    

    cout<<"\nArray2 Elements after copy:\n";
    copyArrayElements(arrLength, arr1, arr2);
    printArray(arr2, arrLength);
    cout<<endl;

    return 0;
}