#include <iostream>

using namespace std;

void printFibonacciSeriesUsingRecursion(short number, int  prev1, int prev2) {

    int fibNumber = 0;

    if (number > 0) {
        fibNumber = prev2 + prev1;
        prev2 = prev1;
        prev1 = fibNumber;
        cout << fibNumber << "   ";
        printFibonacciSeriesUsingRecursion(number - 1, prev1, prev2);
    }
}

int main()
{
    printFibonacciSeriesUsingRecursion(10, 0, 1);

    return 0;
}