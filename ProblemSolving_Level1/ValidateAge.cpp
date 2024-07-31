#include <iostream>

using namespace std;

int readAge(){
    int age;
    cout<<"Enter your Age: ";
    cin>>age;
    return age;
}

bool isValidAge(int age){
    return age>=18 && age<=45;
}

void printResult(int age){
    if(isValidAge(age))
        cout<<"Valid Age";
    else
        cout<<"Invalid Age";
}

int main(){
    printResult(readAge());
    return 0;
}