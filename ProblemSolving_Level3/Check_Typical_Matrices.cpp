#include <iostream>

using namespace std;

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void fillMatrixWithRandomNumber(int Matrix[3][3], short rows, short columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Matrix[i][j] = RandomNumber(1, 10);
        }
    }
}

void printMatrix(int Matrix[3][3], short rows, short columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf(" %0*d  ", 2, Matrix[i][j]);
        }
        cout << endl;
    }
}

bool areTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short rows, short columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Matrix1[i][j] != Matrix2[i][j];
            return false;
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int Matrix2[3][3];

    fillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "\nMatrix1:" << endl;
    printMatrix(Matrix1, 3, 3);

    fillMatrixWithRandomNumber(Matrix2, 3, 3);
    cout << "\nMatrix2:" << endl;
    printMatrix(Matrix2, 3, 3);

    if (areTypicalMatrices(Matrix1, Matrix2, 3, 3)) {
        cout << "\nYes: matrices are typical." << endl;
    }
    else
        cout << "\nNo: matrices aren't typical." << endl;

    return 0;
}
