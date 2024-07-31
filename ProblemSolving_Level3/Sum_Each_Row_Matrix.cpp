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

int RowSum(int arr[3][3], int RowNumber, int cols) {

    int sum = 0;

    for (int j = 0; j < cols; j++) {
        sum += arr[RowNumber][j];
    }
    return sum;
}

void print_Each_Row_Sum(int arr[3][3], short Row, short cols) {
    for (int i = 0; i < Row; i++) {
        cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, cols) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    fillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "The following is a 3x3 random Matrix:" << endl;
    printMatrix(arr, 3, 3);

    cout << "\nThe following are the sum of each row in the Matrix:" << endl;
    print_Each_Row_Sum(arr, 3, 3);

    system("pause>0");

    return 0;
}