#include <iostream>

using namespace std;

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void fillMatrixWithRandomNumber(int Matrix[3][3], short rows, short columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Matrix[i][j] = RandomNumber(0, 1);
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

bool isIdentityMatrix(int Matrix1[3][3], short rows, short columns) {
    for (int i = 0; i < rows; i++) {
        if (Matrix1[i][i] != 1) return false;
        for (int j = 0; j < columns; j++) {
            if (j != i && (Matrix1[i][j] != 0))
                return false;
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    //int Matrix2[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

    fillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "\nMatrix1:" << endl;
    printMatrix(Matrix1, 3, 3);

    if (isIdentityMatrix(Matrix1, 3, 3)) {
        cout << "\nYes: matrix is identity." << endl;
    }
    else
        cout << "\nNo: matrix is not identity." << endl;

    return 0;
}
