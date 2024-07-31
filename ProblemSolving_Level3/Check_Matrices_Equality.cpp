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

int sumMatrixElements(int Matrix[3][3], short rows, short columns) {

    int sumElemnts = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sumElemnts += Matrix[i][j];
        }
    }
    return sumElemnts;
}

bool areEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short rows, short columns) {

    return (sumMatrixElements(Matrix1, rows, columns) == sumMatrixElements(Matrix2, rows, columns));
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int Matrix2[3][3];

    int sumElementsMatrix1 = 0, sumElementsMatrix2 = 0;

    fillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "\nMatrix1:" << endl;
    printMatrix(Matrix1, 3, 3);

    fillMatrixWithRandomNumber(Matrix2, 3, 3);
    cout << "\nMatrix2:" << endl;
    printMatrix(Matrix2, 3, 3);

    if (areEqualMatrices(Matrix1, Matrix2, 3, 3)) {
        cout << "\nYes: matrices are equal." << endl;
    }
    cout << "\nNo: matrices aren't equal." << endl;

    return 0;
}
