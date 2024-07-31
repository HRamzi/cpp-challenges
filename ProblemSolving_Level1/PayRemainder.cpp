#include <iostream>

using namespace std;

float readAmount(string Message){
    float amount;
    do
    {
        cout<<Message;
        cin>>amount;
    } while (amount<=0);

    return amount;
}

float calcAmount(float TotalBill, float CashPaid){
    return CashPaid - TotalBill;
}

int main(){

    float TotalBill = readAmount("Enter the Total Bill:");
    float CashPaid = readAmount("Enter the Cash Paid:");

    cout<<"return: "<<calcAmount(TotalBill, CashPaid);

    return 0;
}