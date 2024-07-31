#include <iostream>
#include <string>

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

void countNumberMatrix(int* Zeroptr, int* Numberptr, int Matrix[3][3], short rows, short columns) {

    int Zeroscounter = 0;
    int NumberCounter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (Matrix[i][j] == 0)
                Zeroscounter++;
            else
                NumberCounter++;
        }
    }
    *Zeroptr = Zeroscounter;
    *Numberptr = NumberCounter;
}

bool isSparseMatrix(int* Zeroptr, int* Numberptr, int Matrix[3][3], short rows, short columns) {

    countNumberMatrix(Zeroptr, Numberptr, Matrix, 3, 3);

    return *Zeroptr > *Numberptr;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];

    int* Zeroptr = &Matrix1[0][0];
    int* Numberptr = &Matrix1[0][0];

    fillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "\nMatrix1:" << endl;
    printMatrix(Matrix1, 3, 3);

    if (isSparseMatrix(Zeroptr, Numberptr, Matrix1, 3, 3))
        cout << "Yes: It is Sparse";
    else
        cout << "No: Itis not Sparse";

    return 0;
}
