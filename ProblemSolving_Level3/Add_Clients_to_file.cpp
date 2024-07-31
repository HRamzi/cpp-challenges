#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;


const string ClientFilleName = "Client.txt";


struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0;
};

stClient readNewClient() {

    stClient Client;

    cout << "Enter Account Number: ";
    getline(cin>>ws, Client.AccountNumber);

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


string convert_record_to_line(stClient Client, string seperator = "#//#") {

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + seperator;
    stClientRecord += Client.PinCode + seperator;
    stClientRecord += Client.Name + seperator;
    stClientRecord += Client.Phone + seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

void addDataLineToFile(string fileName, string sDataLine) {

    fstream myFile;
    myFile.open(fileName, ios::out | ios::app);

    if (myFile.is_open()) {
        myFile << sDataLine << endl;
        myFile.close();
    }
}

void addNewClient() {
	
	stClient client;

	client = readNewClient();
	addDataLineToFile(ClientFilleName, convert_record_to_line(client));
}


void addClients() {

	char AddMore = 'Y';

	do{

		system("cls");
		cout << "Adding new client:\n\n";

		addNewClient();

		cout << "\nNew Client Added Succesfully, Do you want to add more? Y/N ";
		cin >> AddMore;

	}while (toupper(AddMore) == 'Y');
}

int main() {

	addClients();

	return 0;
}