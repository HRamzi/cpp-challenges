#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


struct stClient {
    string AccoutNumber;
    string PinCode;
    string Name;
    string Phone;
    double Accountbalance = 0;
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

	client.AccoutNumber = vectLine[0];
	client.PinCode = vectLine[1];
	client.Name = vectLine[2];
	client.Phone = vectLine[3];
	client.Accountbalance = stod(vectLine[4]);

	return client;
}

void printRecordData(stClient client) {

	cout << "The following is the extracted client record:\n\n";
	cout << "Account Number: " << client.AccoutNumber;
	cout << "\nPin Code      : " << client.PinCode;
	cout << "\nName          : " << client.Name;
	cout << "\nPhone         : " << client.Phone;
	cout << "\nAccount Balance: " << client.Accountbalance;
}

int main()
{
    string line = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
    cout << "Line Record is:";
    cout << "\n" << line;

    cout << "\n" << endl;

	stClient client = convert_lineData_to_record(line);

    printRecordData(client);

    cout << endl;

    return 0;
}