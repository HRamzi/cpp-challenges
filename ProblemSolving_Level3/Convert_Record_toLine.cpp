#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

stClient readNewClient() {
    
    stClient Client;

    cout << "Enter Account Number: ";
    getline(cin, Client.AccountNumber);

    cout << "Enter PinCode: ";
    getline(cin, Client.PinCode);

    cout << "Enter Name: ";
    getline(cin, Client.Name);

    cout << "Enter Phone: ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}


string convert_record_to_line(stClient Client, string seperator="#//#") {

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + seperator;
    stClientRecord += Client.PinCode + seperator;
    stClientRecord += Client.Name + seperator;
    stClientRecord += Client.Phone + seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

int main() {
    
    stClient client;

    cout << "Please Enter Client Data:\n\n";
    client = readNewClient();

    cout << "\nClient Record for Saving is:\n";
    cout << convert_record_to_line(client) << endl;

    return 0;
}
