#include <iostream>

using namespace std;

void printFibonacciSeriesUsingLoop(short number) {

    int fibNumber = 0;
    int Prev2 = 0, Prev1 = 1;

    cout << "1   ";
    for (int i = 2; i <= number; i++) {
        fibNumber = Prev1 + Prev2;
        cout << fibNumber << "   ";
        Prev2 = Prev1;
        Prev1 = fibNumber;
    }
}

int main()
{
    printFibonacciSeriesUsingLoop(10);

    return 0;
}