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

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    fillMatrixWithRandomNumber(Matrix, 3, 3);

    cout << "\nMatrix1:" << endl;
    printMatrix(Matrix, 3, 3);

    cout << "\nSum of Matrix is: " << sumMatrixElements(Matrix, 3, 3) << endl;
}
