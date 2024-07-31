#include <iostream>

using namespace std;

float readBillValue(){
    float BillValue;
    cout<<"Enter Bill Value:\n";
    cin>>BillValue;
    return BillValue;
}

float calcTotalBill(float BillValue){
    const float FEE = 0.1;
    const float SALESTAX = 0.16;
    float TotalBill = BillValue*FEE;
          TotalBill += TotalBill*SALESTAX;
    return TotalBill;
}

int main(){

    cout<<"Total Bill after service fee and sales tax: "<<calcTotalBill(readBillValue())<<"$"<<endl;

    return 0;
}