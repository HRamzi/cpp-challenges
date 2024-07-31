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

bool isPalindromeMatrix(int Matrix[3][3], short rows, short columns) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns/2; j++) {
            if (Matrix[i][j] != Matrix[i][columns - 1 - j]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));


    int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };


    cout << "\nMatrix1:\n";
    printMatrix(Matrix1, 3, 3);

    if (isPalindromeMatrix(Matrix1, 3, 3)) {
        cout << "\nYes: Matrix is palindrome" << endl;
    }
    else {
        cout << "\nNo: Matrix is NOT a palindrome" << endl;
    }

    return 0;
}
