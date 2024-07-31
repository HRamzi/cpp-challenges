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

int maxRandomArray(int *arr, int arrLength){
    int max = arr[0];
    for(int i=1; i<arrLength; i++){
        if(max<arr[i])
            max = arr[i];
    }
    return max;
}

int main(){

    srand((unsigned)time(NULL));
    int arr[100], arrLength;

    arrLength = readNumber("\nEnter a Number: ");

    fillArrayWithRandomNumbers(arr, arrLength);

    cout<<"\nArray Elements: ";
    printArray(arr, arrLength);
    

    cout<<"Max Number is: ";
    cout<<maxRandomArray(arr, arrLength)<<endl;

    return 0;
}