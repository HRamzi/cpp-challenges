#include <iostream>
#include <string>

using namespace std;

int RandomNumber(int From, int To) {
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void fillArraywithRandomNumbers(int arr[3][3], short Rows, short Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void printMiddleRow(int arr[3][3]) {
	int i = 1;
	for (int j = 0; j < 3; j++) {
		cout << arr[i][j]<<" ";
	}
	cout << endl;
}

void printMiddleCol(int arr[3][3]) {
	int j = 1;
	for (int i = 0; i < 3; i++) {
		cout << arr[i][j] << " ";
	}
	cout << endl;
}

void printMatrix(int arr[3][3], short Rows, short Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			printf("%02d ", arr[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}


int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];
	fillArraywithRandomNumbers(arr, 3, 3);

	cout << "Matrix:" << endl;
	printMatrix(arr, 3, 3);

	cout << "Middle Row of Matrix is:\n";
	printMiddleRow(arr);

	cout << endl;

	cout << "Middle Col of Matrix is:\n";
	printMiddleCol(arr);

	return 0;
}