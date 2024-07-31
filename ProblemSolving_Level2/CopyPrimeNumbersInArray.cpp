#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum NumType {Prime = 1, NotPrime = 2};

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

NumType isPrime(int Element){
    int M = round(Element / 2);
    for(int i=2; i<=M; i++){
        if(Element%i == 0)
            return NumType::NotPrime;
    }
   return NumType::Prime;
}

void copyPrimeElements(int arr1Length, int *arrSource, int *arrDestionation, int &arr2Length){
    int counter = 0;
    for(int i=0; i<arr1Length; i++){
        if(isPrime(arrSource[i]) == NumType::Prime){
            arrDestionation[counter] = arrSource[i];
            counter++;
        }
    }
    arr2Length = --counter;
}

void printArray(int *arr, int arrLength){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

int main(){

    srand((unsigned)time(NULL));

    int arr1[100], arr1Length;
    arr1Length = readNumber("\nEnter a Number: ");
    fillArrayWithRandomNumbers(arr1, arr1Length);

    int arr2[100], arr2Length=0;
    copyPrimeElements(arr1Length, arr1, arr2, arr2Length);

    cout<<"\nArray1 Elements:\n";
    printArray(arr1, arr1Length);

    cout<<"\nPrime Numbers in Array2:\n";
    printArray(arr2, arr2Length);
    cout<<endl;

    return 0;
}