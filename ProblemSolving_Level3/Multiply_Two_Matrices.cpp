#include <iostream>
#include <string>

using namespace std;

int randomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void fillMatrixWithRandomNumbers(int arr[3][3], int Rows, int cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = randomNumber(10, 100);
        }
    }
}

void printMatrix(int arr[3][3], int Rows, int cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%0*d ", 2, arr[i][j]);
        }
        cout << endl;
    }
}

void multiplyTwoMatrices(int arrResult[3][3], int arr1[3][3], int arr2[3][3], int Rows, int cols) {
    int sum = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < cols; j++) {
            arrResult[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3], arr2[3][3];
    int arrResult[3][3];

    cout << "\nMatrix1:\n";
    fillMatrixWithRandomNumbers(arr1, 3, 3);
    printMatrix(arr1, 3, 3);
    cout << "\n" << endl;

    cout << "Matrix2:\n";
    fillMatrixWithRandomNumbers(arr2, 3, 3);
    printMatrix(arr2, 3, 3);
    cout << "\n" << endl;

    cout << "Result:\n";
    multiplyTwoMatrices(arrResult, arr1, arr2, 3, 3);
    printMatrix(arrResult, 3, 3);
   
    return 0;
}