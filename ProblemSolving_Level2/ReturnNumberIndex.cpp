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

void printArray(int *arr, int arrLength){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int findNumberPositionInArray(int *arr, int arrlength, int number){
    for(int i=0; i<arrlength; i++){
        if(arr[i] == number)
            return i;
    }
    return -1;
}

int main(){

    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    arrLength = readNumber("\nEnter Number of Elments: ");
    fillArrayWithRandomNumbers(arr, arrLength);

    cout<<"\nArray Elements:\n";
    printArray(arr, arrLength);

    int Number = readNumber("\nEnter a number to search for:\n");
    cout<<"\nNumber you are looking for is: "<<Number<<endl;

    short numberPosition = findNumberPositionInArray(arr, arrLength, Number);

    if(numberPosition == -1)
        cout<<"The number is not found :-(\n"<<endl;
    else{
        cout<<"\nThe number found at the position: "<<numberPosition<<endl;
        cout<<"The number found its order: "<<numberPosition+1;
    }
    cout<<endl;
    cout<<endl;

    return 0;
}