#include <iostream>

using namespace std;

struct stDriverInfo{
    int age;
    bool HasDrivingLicense;
};

stDriverInfo readInfo(){

    stDriverInfo driver;

    cout<<"Age: ";
    cin>>driver.age;

    cout<<"Driving License: ";
    cin>>driver.HasDrivingLicense;

    return driver;
}

bool isAccepted(stDriverInfo driver){

    return driver.age>21 && driver.HasDrivingLicense;
}

void printResult(stDriverInfo driver){

    if(isAccepted(driver))
        cout<<"you're Hired\n";
    else
        cout<<"you're Rejected\n";
}

int main(){
    printResult(readInfo());
    return 0;
}