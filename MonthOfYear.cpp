#include <iostream>
#include <string>

using namespace std;

enum enDayOfWeek{Jan=1, Feb=2, Mar=3, Apr=4, May=5, Jun=6,
                 Jul=7, Aug=8, Sep=9, Oct=10, Nov=11, Dec=12};

int readNumberInRang(string Message, int from, int To){

    int Number;

    do{
        cout<<Message;
        cin>>Number;
    }while(Number<from || Number>To);

    return Number;
}

enDayOfWeek readDayOfWeek(){

    return (enDayOfWeek)readNumberInRang("Please Enter Month Number\n", 1, 12);
}

string getDayOfWeek(enDayOfWeek Day){

    switch(Day){
        case enDayOfWeek::Jan:
            return "it's Janvier";
        case enDayOfWeek::Feb:
            return "it's Februry";
        case enDayOfWeek::Mar:
            return "it's March";
        case enDayOfWeek::Apr:
            return "it's April";
        case enDayOfWeek::May:
            return "it's May";
        case enDayOfWeek::Jun:
            return "it's June";
        case enDayOfWeek::Jul:
            return "it's Jully";
        case enDayOfWeek::Aug:
            return "it's auguest";
        case enDayOfWeek::Sep:
            return "it's Septembre";
        case enDayOfWeek::Oct:
            return "it's October";
        case enDayOfWeek::Nov:
            return "it's Novomber";
        case enDayOfWeek::Dec:
            return "it's December";
        default:
            return " ";
    }
}

int main(){

    cout<<getDayOfWeek(readDayOfWeek())<<endl;

    return 0;
}