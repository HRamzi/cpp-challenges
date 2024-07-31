#include <iostream>
#include <string>

using namespace std;

int readPositiveNumbers(string Message){
    int NumberOfHours;

    do{
        cout<<Message;
        cin>>NumberOfHours;
    }while(NumberOfHours<0);

    return NumberOfHours;
}

float numberOfWeeks(int NumberOfHours){
    float NumberOfWeeks = (float)NumberOfHours /24 /7;
    return NumberOfWeeks;
}

float numberOfDays(int NumberOfHours){
    float NumberOfDays = (float)NumberOfHours/24;
    return NumberOfDays;
}

int main(){

    int NumberOfHours = readPositiveNumbers("Enter Number of Hours\n");

    cout<<endl;
    cout<<numberOfWeeks(NumberOfHours)<<" "<<"weeks\n";
    cout<<numberOfDays(NumberOfHours)<<" "<<"days"<<endl;

    return 0;
}