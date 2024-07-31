#include <iostream>
#include <string>
using namespace std;

int readNumber(string msg){
    int num; 
    cout<<msg;
    cin>>num;
    return num;
}

void addArrayElements(int &arrLength, int *arr, int Number){
    arrLength++;
    arr[arrLength-1] = Number;
}

void InputUserNumbersInArray(int &arrLength, int *arr){
    bool addMore;
    do{
        addArrayElements(arrLength, arr, readNumber("\nEnter a Number? "));
        cout<<"Do you want to add more numbers?[0]:No,[1]:Yes? ";
        cin>>addMore;
    }while(addMore);
}

void printArray(int arrLength, int *arr){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    int arr[100], arrLength=0;

    InputUserNumbersInArray(arrLength, arr);

    cout<<"\nArray Length: "<<arrLength<<endl;
    cout<<"Array Elements: ";
    printArray(arrLength, arr);
    cout<<"\n";

    return 0;
}