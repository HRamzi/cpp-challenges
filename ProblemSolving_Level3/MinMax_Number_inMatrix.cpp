#include <iostream>
#include <iomanip>

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

int MinNumberMatrix(int Matrix[3][3], short rows, short columns) {

    int MinNumber = Matrix[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (Matrix[i][j] < MinNumber) {
                MinNumber = Matrix[i][j];
            }
        }
    }
    return MinNumber;
}

int MaxNumberMatrix(int Matrix[3][3], short rows, short columns) {

    int MaxNumber = Matrix[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (Matrix[i][j] > MaxNumber) {
                MaxNumber = Matrix[i][j];
            }
        }
    }
    return MaxNumber;
}

int main()
{
    srand((unsigned)time(NULL));


    int Matrix1[3][3] = { {77,5,12},{22,20,3},{2,16,99} };


    cout << "\nMatrix1:\n";
    printMatrix(Matrix1, 3, 3);

    cout << "\nMinimum Number is: " << MinNumberMatrix(Matrix1, 3, 3) << "\n";
    cout << "Max Number is: " << MaxNumberMatrix(Matrix1, 3, 3) << endl;

    return 0;
}
