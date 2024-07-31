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

vector<stClient> loeadClientDataFromFile(string fileName) {

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

bool findClientByAccountNumber(stClient & client, string AccountNumber) {

	vector<stClient> vectClient = loeadClientDataFromFile(ClientFilleName);

	for (stClient element : vectClient) {
		if (element.AccountNumber == AccountNumber) {
			client = element;
			return true;
		}
	}
	return false;
}

int main() {

	stClient client;
	string AccountNumber = readClientAccountNumber();

	if (findClientByAccountNumber(client, AccountNumber)) {
		printClientdetails(client);
	}
	else {
		cout<<"\nClient with Account Number ("<< AccountNumber <<") is not Found!";
	}

	cout << endl;

	return 0;
}