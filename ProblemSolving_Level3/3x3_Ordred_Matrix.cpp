#include <iostream>

using namespace std;

void fillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short cols) {

    int count = 1;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = count++;
        }
    }
}

void printMatrix(int arr[3][3], short Rows, short cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "  " << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{

    int arr[3][3];

    fillMatrixWithOrderedNumbers(arr, 3, 3);

    cout << "the following is a 3x3 ordered Matrix:" << endl;
    printMatrix(arr, 3, 3);

    return 0;
}