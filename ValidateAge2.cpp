#include <iostream>

using namespace std;

void readAge(){

    int age;

    do
    {
        cout<<"Enter your age: ";
        cin>>age;
    
    } while (age<18 || age>45);

}

int main(){

    readAge();

    return 0;
}