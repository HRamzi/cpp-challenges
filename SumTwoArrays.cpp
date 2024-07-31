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

void fillArrayWithRandomNumbers(int *arr, int &arrLength){
    for(int i=0; i<arrLength; i++){
        arr[i] = randomNum(1, 100);
    }
}

void sumElements(int arrLength, int *arr1, int *arr2, int *arrSum){
    for(int i=0; i<arrLength; i++){
        arrSum[i] = arr1[i] + arr2[i];
    }
}

void printArray(int *arr, int arrLength){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    srand((unsigned)time(NULL));

    int arrLength = readNumber("Enter the Length of both Arrays: ");

    int arr1[100];
    fillArrayWithRandomNumbers(arr1, arrLength);

    int arr2[100];
    fillArrayWithRandomNumbers(arr2, arrLength);

    cout<<"\nArray1 Elements:\n";
    printArray(arr1, arrLength);

    cout<<"\nArray2 Elements:\n";
    printArray(arr2, arrLength);

    int arrSum[100];
    sumElements(arrLength, arr1, arr2, arrSum);

    cout<<"\nSum of array1 and array2 elements:\n";
    printArray(arrSum, arrLength);
    cout<<"\n";

    return 0;
}