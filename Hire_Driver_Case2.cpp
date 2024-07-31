#include <iostream>

using namespace std;

struct stDriverInfo{
    int age;
    bool HasDrivingLicense;
    bool HasRecommendation;
};

stDriverInfo readInfo(){

    stDriverInfo driver;

    cout<<"Age: ";
    cin>>driver.age;

    cout<<"Driver License: ";
    cin>>driver.HasDrivingLicense;

    cout<<"Recommendation: ";
    cin>>driver.HasRecommendation;

    return driver;
}

bool isAccepted(stDriverInfo driver){

    if(driver.HasRecommendation)
        return true;
    else
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