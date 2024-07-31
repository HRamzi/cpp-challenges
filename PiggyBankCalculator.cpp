#include <iostream>
#include <string>

using namespace std;

struct stPiggyBankContent{

    int pennies, nickels, dimes, quarters, dollars;
};

stPiggyBankContent readPiggyBankContent(){

    stPiggyBankContent PiggyBankContent;

    cout<<"Please enter the total of:\n";

    cout<<"- pennies :";
    cin>>PiggyBankContent.pennies;

    cout<<"- nickels :";
    cin>>PiggyBankContent.nickels;

    cout<<"- dimes :";
    cin>>PiggyBankContent.dimes;

    cout<<"- quarters :";
    cin>>PiggyBankContent.quarters;

    cout<<"- dollars :";
    cin>>PiggyBankContent.dollars;

    return PiggyBankContent;
}

int calcTotalPennies(stPiggyBankContent PiggyBankContent){

    int TotalPennies = 0;

    TotalPennies = PiggyBankContent.pennies + PiggyBankContent.nickels*5
                + PiggyBankContent.dimes*10 + PiggyBankContent.quarters*25
                    + PiggyBankContent.dollars*100;

    return TotalPennies;
}

int main(){

    int TotalPennies = calcTotalPennies(readPiggyBankContent());

    cout<<endl<<"Total Pennies: "<<TotalPennies<<endl;
    cout<<endl<<"Total Dollars: "<<(float)TotalPennies/100<<endl;

    return 0;
}