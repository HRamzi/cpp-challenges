#include <iostream>
#include <string>

using namespace std;

enum enDayOfWeek{Sat=1, Sun=2, Mon=3, Tue=4, Wed=5, Thu=6, Fri=7};

int readNumberInRang(string Message, int from, int To){

    int Number;

    do{
        cout<<Message;
        cin>>Number;
    }while(Number<from || Number>To);

    return Number;
}

enDayOfWeek readDayOfWeek(){

    return (enDayOfWeek)readNumberInRang("Please Enter Day Number\n", 1, 7);
}

string getDayOfWeek(enDayOfWeek Day){

    switch(Day){
        case enDayOfWeek::Sat:
            return "it's Saturday";
        case enDayOfWeek::Sun:
            return "it's Sunday";
        case enDayOfWeek::Mon:
            return "it's Monday";
        case enDayOfWeek::Tue:
            return "it's Tuesday";
        case enDayOfWeek::Wed:
            return "it's Wednesday";
        case enDayOfWeek::Thu:
            return "it's Thursday";
        case enDayOfWeek::Fri:
            return "it's Friday";
        default:
            return " ";
    }
}

int main(){

    cout<<getDayOfWeek(readDayOfWeek())<<endl;

    return 0;
}