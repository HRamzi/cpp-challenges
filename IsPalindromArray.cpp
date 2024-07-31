#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int arrLength, int *arr){
    for(int i=0; i<arrLength; i++){
        if(arr[i] != arr[arrLength-i-1])
            return false;
    }
    return true;
}

void printArray(int &arrLength, int *arr){
    for(int i=0; i<arrLength; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    int arrLength = 6;
    int arr[] = {10, 20, 30, 30, 20, 10};

    cout<<"\nArray elements:\n";
    printArray(arrLength, arr);

    if(isPalindrome(arrLength, arr))
        cout<<"\nYes! Array is Palindrome\n\n";
    else
        cout<<"\nNo! Array is not Palindrome\n\n";

    return 0;
}