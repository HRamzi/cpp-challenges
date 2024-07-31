#include <iostream>

using namespace std;

void fillMatrixWithOredredNumbers(int arr[3][3], short Rows, short cols) {

    int count = 1;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = count++;
        }
    }
}

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short cols) {
    
    int temp;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < cols; j++) {
            arrTransposed[i][j] = arr[j][i];
        }
    }
}

void printMatrix(int arr[3][3], short Rows, short cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << " " << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{

    int arr[3][3];
    int arrTransposed[3][3];

    fillMatrixWithOredredNumbers(arr, 3, 3);
    cout << "The following is a 3x3 ordered Matrix:" << endl;
    printMatrix(arr, 3, 3);

    TransposeMatrix(arr, arrTransposed, 3, 3);

    cout << "\nThe folowing is the transpose Matrix" << endl;
    printMatrix(arrTransposed, 3, 3);

    return 0;
}