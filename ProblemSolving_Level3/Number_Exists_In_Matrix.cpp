#include <iostream>
#include <string>

using namespace std;

int readNumber(string msg) {
    int number;

    cout << msg;
    cin >> number;

    return number;
}

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


bool doesNumberExists(int numToLook, int Matrix[3][3], short rows, short columns) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (Matrix[i][j] == numToLook)
                return true;
        }
    }
    return false;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int numToLook;

    fillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "\nMatrix1:" << endl;
    printMatrix(Matrix1, 3, 3);

    numToLook = readNumber("\nEnter the number to look for in Matrix? ");

    if (doesNumberExists(numToLook, Matrix1, 3, 3))
        cout << "\nYes it is there." << endl;
    else
        cout << "No it is not there" << endl;

    return 0;
}
