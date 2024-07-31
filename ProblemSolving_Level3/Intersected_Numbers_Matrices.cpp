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


bool doesNumberExists(int numToLook, int Matrix[3][3], short rows, short columns) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (Matrix[i][j] == numToLook)
                return true;
        }
    }
    return false;
}

void printIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short rows, short columns) {
    int number;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            number = Matrix1[i][j];
            if(doesNumberExists(number, Matrix2, 3, 3))
                cout<< setw(3) << number << "     ";
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

    cout << "\nMatrix1:\n";
    printMatrix(Matrix1, 3, 3);
    cout << "\nMatrix2:\n";
    printMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbers are: \n";
    printIntersectedNumbers(Matrix1, Matrix2, 3, 3);
    cout << endl;


    return 0;
}
