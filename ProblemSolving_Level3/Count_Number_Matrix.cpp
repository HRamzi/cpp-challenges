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

int countNumberMatrix(int numToCount, int Matrix[3][3], short rows, short columns) {
    
    int Numbercount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (Matrix[i][j] == numToCount)
                Numbercount++;
        }
    }
    return Numbercount;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int numToCount;

    fillMatrixWithRandomNumber(Matrix1, 3, 3);
     cout << "\nMatrix1:" << endl;
    printMatrix(Matrix1, 3, 3);

    numToCount = readNumber("\nEnter the number to count in Matrix? ");

    cout << "\nNumber " << numToCount << " count in Matrix is " << countNumberMatrix(numToCount, Matrix1 , 3, 3) << endl;

    return 0;
}
