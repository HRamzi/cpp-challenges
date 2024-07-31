#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct stSecToDayHrsMin
{
    int days, hours, min, sec;
};


int readPositiveNumber(string Message){

    int Number;

    do{
        cout<<Message;
        cin>>Number;
    }while(Number<0);

    return Number;
}

stSecToDayHrsMin secondsToTaskDuration(int TotalSeconds){

    stSecToDayHrsMin TaskDuration;

    const int SecondsPerDay = 24*60*60;
    const int SecondsPerHour = 60*60;
    const int SecondsPerMinute = 60;

    int Remainder = 0;

    TaskDuration.days = floor(TotalSeconds /SecondsPerDay);
    Remainder = TotalSeconds % SecondsPerDay;
    TaskDuration.hours = floor(Remainder /SecondsPerHour);
    Remainder = TotalSeconds % SecondsPerHour;
    TaskDuration.min = floor(Remainder /SecondsPerMinute);
    Remainder = TotalSeconds % SecondsPerMinute;
    TaskDuration.sec = Remainder;

    return TaskDuration;
}

void printTaskDuration(stSecToDayHrsMin TaskDuration){

    cout<<"\n";
    cout<<TaskDuration.days<<":"
        <<TaskDuration.hours<<":"
        <<TaskDuration.min<<":"
        <<TaskDuration.sec<<"\n";
}

int main(){

    int TotalSeconds = readPositiveNumber("Please Enter Total of Seconds\n");
    printTaskDuration(secondsToTaskDuration(TotalSeconds));

    return 0;
}