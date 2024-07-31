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

vector<stClient> leadClientDataFromFile(string fileName) {

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

void printClientRecord(stClient client) {

	cout << "| " << left << setw(15) << client.AccountNumber;
	cout << "| " << left << setw(10) << client.PinCode;
	cout << "| " << left << setw(40) << client.PinCode;
	cout << "| " << left << setw(12) << client.Phone;
	cout << "| " << left << setw(12) << client.AccountBalance;
}

void printAllClientData(vector<stClient> vectClient) {

	cout << "\n\t\t\t\t\tClient List (" << vectClient.size() << ") Client(s)";
	cout << "\n_________________________________________________________";
	cout << "___________________________________________\n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_________________________________________________________";
	cout << "___________________________________________\n";

	for (stClient client : vectClient) {
		printClientRecord(client);
		cout << endl;
	}
}

int main() {

    vector<stClient> vectClient = leadClientDataFromFile(ClientFilleName);

	printAllClientData(vectClient);

    return 0;
}