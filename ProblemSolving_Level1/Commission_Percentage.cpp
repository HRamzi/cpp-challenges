#include <iostream>

using namespace std;

int readTotaleSales(){

    int TotalSale;

    cout<<"Enter the Totale Sales: \n";
    cout<<"--> ";
    cin>>TotalSale;

    return TotalSale;
}

float getCommissionPercentage(float Totalsales){

    if(Totalsales>=1000000)
        return 0.01;
    else if(Totalsales>=500000)
        return 0.02;
    else if(Totalsales>=100000)
        return 0.03;
    else if(Totalsales>=50000)
        return 0.05;
    else
        return 0.00;
}

float calcTotalCommission(float Totalsales){
    return getCommissionPercentage(Totalsales) * Totalsales;
}

int main(){

    float TotalSale = readTotaleSales();

    cout<<endl<<"Commission Percentage: "<<getCommissionPercentage(TotalSale);
    cout<<endl<<"Total Commission: "<<calcTotalCommission(TotalSale)<<"$"<<endl;


    return 0;
}