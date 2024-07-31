#include <iostream>

using namespace std;

string readPinCode(){

    string PinCode;

    cout<<"please enter PIN code\n";
    cin>>PinCode;

    return PinCode;
}

bool login(){

    int counter = 0;
    string PinCode;

    do{
        counter++;
        PinCode = readPinCode();

        if(PinCode == "1234")
            return 1;
        else
        {
            cout<<"Wrong PIN\n";
            system("color 4F");
        }

    }while(counter<3 && PinCode != "1234");

    return 0;
}

int main(){

    if(login()){
        system("color 2F");
        cout<<"your Balance is: 7500$";
    }
    else
        cout<<"your card is blocked call the bank for help";

    return 0;
}