#include <iostream>

using namespace std;

int readPositiveNumbers(string Message){
    int Number;

    do{
        cout<<Message;
        cin>>Number;
    }while(Number<0);

    return Number;
}

float calcMonthlyInstallmentAmount(float LoanAmount, int MonthsPayment){
    return LoanAmount / MonthsPayment;
}

int main(){

    float LoanAmount = (float)readPositiveNumbers("Enter The amount you want to Loan:\n");
    int MonthsPayment = readPositiveNumbers("Enter number of Month you want to pay this Loan:\n");

    cout<<endl<<"The monthly installment amount is: "<<calcMonthlyInstallmentAmount(LoanAmount, MonthsPayment)<<endl;

    return 0;
}