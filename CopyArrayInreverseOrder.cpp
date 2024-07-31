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

void ArrayElementInReverseOrder(int arrLength, int *arrSource, int *arrDestionation){
    int counter = 0;
    for(int i=0; i<arrLength; i++)
        arrDestionation[i] = arrSource[arrLength-1-i];
        
}

void printArray(int *arr, int arrLength){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

int main(){

    srand((unsigned)time(NULL));

    int arrLength = readNumber("Enter the Length Array: ");

    int arr1[100];
    fillArrayWithRandomNumbers(arr1, arrLength);

    cout<<"\nArray1 Elements:\n";
    printArray(arr1, arrLength);

    int arr2[100];
    ArrayElementInReverseOrder(arrLength, arr1, arr2);

    cout<<"\nArray2 Elements after copying array1 in reversed order:\n";
    printArray(arr2, arrLength);
    cout<<"\n";

    return 0;
}