#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

enum PrimeNotPrime{Prime = 1, NotPrime = 2};

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

PrimeNotPrime isPrime(int num){
    int i = round(num/2);
    for(int count=2; count<=i; count++){
        if(num % count == 0)
            return PrimeNotPrime::NotPrime;
    }
    return PrimeNotPrime::Prime;
}

void addArrayElements(int &arr2Length, int *arr, int Number){
    arr2Length++;
    arr[arr2Length-1] = Number;
}

void copyPrimeElements(int arrSourceLength, int &arrDestinationLength, int *arrSource, int *arrDestination){
    for(int i=0; i<arrSourceLength; i++){
        if(isPrime(arrSource[i]) == PrimeNotPrime::Prime)
            addArrayElements(arrDestinationLength, arrDestination, arrSource[i]);
    }
}

int main(){

    srand((unsigned)time(NULL));

    int arr1length;
    arr1length = readNumber("Enter number of Array Elements: \n");

    int arr1[100];
    fillArrayWithRandomNumbers(arr1length, arr1);

    cout<<"\nArray 1 elements:\n";
    printArray(arr1length, arr1);

    int arr2[100], arr2length=0;
    copyPrimeElements(arr1length, arr2length, arr1, arr2);

    cout<<"\nArray 2 Prime numbers:\n";
    printArray(arr2length, arr2);

    cout<<"\n";

    return 0;
}