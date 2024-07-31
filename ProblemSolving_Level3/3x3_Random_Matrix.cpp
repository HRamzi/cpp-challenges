#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void fillMatrixWithRandomNumbers(int arr[3][3], short Rows, short cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < cols; j++) {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void printMatrix(int arr[3][3], short Rows, short cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }

        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    fillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "the following is a 3x3 random Matrix:" << endl;
    printMatrix(arr, 3, 3);

    system("pause>0");

    return 0;
}