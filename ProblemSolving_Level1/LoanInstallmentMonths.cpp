#include <iostream>

using namespace std;

float readPositiveNumbers(string Message){
    float Number;

    do{
        cout<<Message;
        cin>>Number;
    }while(Number<0);

    return Number;
}

float calcNumberOfMonths(float LoanAmount, float MonthlyPayment){
    return LoanAmount / MonthlyPayment;
}

int main(){

    float LoanAmount, MonthlyPayment;

    LoanAmount = readPositiveNumbers("Enter The amount you want to Loan:\n");
    MonthlyPayment = readPositiveNumbers("Enter The amount that you can pay per Month:\n");

    cout<<endl<<"Number of Mnths is: "<<calcNumberOfMonths(LoanAmount, MonthlyPayment)<<" "<<"Months"<<endl;

    return 0;
}