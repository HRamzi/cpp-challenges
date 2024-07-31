#include <iostream>
#include <string>

using namespace std;

struct stTaskDuration
{
    int days, hours, minutes, seconds;
};


int readPositiveNumbers(string Message){
    int Number;

    do{
        cout<<Message;
        cin>>Number;
    }while(Number<0);

    return Number;
}

stTaskDuration readTaskDuration(){

    stTaskDuration duration;

    duration.days = readPositiveNumbers("Days: ");
    duration.hours = readPositiveNumbers("Hours: ");
    duration.minutes = readPositiveNumbers("Minutes: ");
    duration.seconds = readPositiveNumbers("seconds: ");

    return duration;
}

int totalDurationInseconds(stTaskDuration duration){

    int TotalDurationInSec = (duration.days*24*3600) + (duration.hours*3600)
                             + (duration.minutes*60) + duration.seconds;

    return TotalDurationInSec;
}

int main(){

    stTaskDuration duration;

    cout<<"Enter Task Duration\n";
    duration = readTaskDuration();
    cout<<endl<<"Task Duration in seconds: "<<totalDurationInseconds(duration)<<"s"<<endl;

    return 0;
}