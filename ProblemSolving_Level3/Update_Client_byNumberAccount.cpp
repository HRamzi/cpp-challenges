#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


const string ClientFilleName = "Client.txt";


struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
	bool MarkForDelete = false;
};

string readClientAccountNumber() {

	string AccountNumber = "";
	cout << "Please Enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}

vector<string> splitString(string str, string delim) {

	short pos = 0;
	string sWord;

	vector<string> vectWord;

	while ((pos = str.find(delim)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != " ") {
			vectWord.push_back(sWord);
		}
		str.erase(0, pos + delim.length());
	}
	if (str != " ") {
		vectWord.push_back(str);
	}

	return vectWord;
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

stClient convert_lineData_to_record(string line) {

	stClient client;

	vector<string> vectLine = splitString(line, "#//#");

	client.AccountNumber = vectLine[0];
	client.PinCode = vectLine[1];
	client.Name = vectLine[2];
	client.Phone = vectLine[3];
	client.AccountBalance = stod(vectLine[4]);

	return client;
}

vector<stClient> loadClientDataFromFile(string fileName) {

	vector<stClient> vectClient;

	fstream Myfile;
	Myfile.open(fileName, ios::in);


	if (Myfile.is_open()) {

		string line;
		stClient client;

		while (getline(Myfile, line)) {
			client = convert_lineData_to_record(line);
			vectClient.push_back(client);
		}

		Myfile.close();
	}

	return vectClient;
}

void printClientdetails(stClient client) {
	cout << "The following is the extracted client record:\n\n";
	cout << "Account Number: " << client.AccountNumber;
	cout << "\nPin Code      : " << client.PinCode;
	cout << "\nName          : " << client.Name;
	cout << "\nPhone         : " << client.Phone;
	cout << "\nAccount Balance: " << client.AccountBalance;
}

bool findClientByAccountNumber(vector<stClient> vectClient, stClient& client, string AccountNumber) {

	vector<stClient> vectClient = loadClientDataFromFile(ClientFilleName);

	for (stClient element : vectClient) {
		if (element.AccountNumber == AccountNumber) {
			client = element;
			return true;
		}
	}
	return false;
}

vector<stClient> saveClientDataToFile(string fileName, vector<stClient> vectClient) {

	fstream MyFile;
	MyFile.open(fileName, ios::out);

	string DataLine;

	if (MyFile.is_open()) {

		for (stClient C : vectClient) {

			if (C.MarkForDelete == false) {
				DataLine = convert_record_to_line(C);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}
	return vectClient;
}

stClient changeClientRecord(string AccountNumber) {

	stClient client;

	client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode: ";
	getline(cin>>ws, client.PinCode);

	cout << "Enter Name: ";
	getline(cin, client.Name);

	cout << "Enter Phone: ";
	getline(cin, client.Phone);

	cout << "Enter Account Balance: ";
	cin >> client.AccountBalance;

	return client;
}

bool updateClientByAccountNumber(vector<stClient>& vectClient, string AccountNumber) {

	stClient client;
	char Answer = 'n';

	if (findClientByAccountNumber(vectClient, client, AccountNumber)) {

		printClientdetails(client);

		cout << "\n\nAre you sure you want to update this client? y/n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {

			for (stClient & C : vectClient) {
				
				if (C.AccountNumber == AccountNumber) {

					C = changeClientRecord(AccountNumber);
					break;
				}
			}

			saveClientDataToFile(ClientFilleName, vectClient);

			cout << "\n\nClient Updated Successfully";
			return true;
		}
	}
	return false;
}

int main() {

	vector<stClient> vectClient = loadClientDataFromFile(ClientFilleName);
	string AccountNumber = readClientAccountNumber();

	updateClientByAccountNumber(vectClient, AccountNumber);

	cout << endl;

	return 0;
}