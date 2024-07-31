#include <iostream>
#include <string>
using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

void readArray(int *arr, int &arrlength){

    cout<<"Entr number of elements:\n";
    cin>>arrlength;

    cout<<"\nEnter Elements of the Array:\n";

    for(int i=0; i<arrlength; i++){
        cout<<"Element["<<i+1<<"] : ";
        cin >> arr[i];
    }
    cout<<endl;
}

void printArray(int *arr, int arrLength){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

int timesRepeated(int numberToCheck, int *arr, int arrLength){
    int count = 0;
    for(int i=0; i<arrLength; i++){
        if(numberToCheck == arr[i])
            count++;
    }
    return count;
}


int main(){

    int arr[100], arrlength, numberToCheck;

    readArray(arr, arrlength);

    numberToCheck = readNumber("Enter the number you want to check: ");

    cout<<"\nOriginal Array: ";
    printArray(arr, arrlength);

    cout<<"\nNumber "<<numberToCheck;
    cout<<" is repeated ";
    cout<<timesRepeated(numberToCheck, arr, arrlength)<<" time(s)";

    return 0;
}