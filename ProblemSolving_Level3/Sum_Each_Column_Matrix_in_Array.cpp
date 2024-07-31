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

int ColSum(int arr[3][3], short Rows, short ColNumber){
    int Sum = 0; 
    for (short i = 0; i <= Rows - 1; i++){
        Sum += arr[i][ColNumber];
    }
    return Sum;
}

void SumMatixColsInArry(int arrSum[3], int arr[3][3], short Rows, short Cols){
    for (short i = 0; i < Cols; i++){
        arrSum[i] = ColSum(arr, Rows, i);
    }
}

void print_Sum_Each_col_Matrix(int arrColSum[3], short length) {
    for (int j = 0; j < length; j++) {
        cout << " Col " << j + 1 << " Sum = " << arrColSum[j] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrColSum[3];

    fillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "The following is a 3x3 random Matrix:" << endl;
    printMatrix(arr, 3, 3);

    SumMatixColsInArry(arrColSum, arr, 3, 3);

    cout << "\nThe following are the sum of each row in the Matrix:" << endl;
    print_Sum_Each_col_Matrix(arrColSum, 3);

    system("pause>0");

    return 0;
}