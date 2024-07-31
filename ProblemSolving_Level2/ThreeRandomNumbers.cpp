#include <iostream>
#include <cstdlib>
using namespace std;

int randomNum(int from, int To){
    int randNum = rand() % (To - from + 1) + from;
    return randNum;
}

int main(){
    srand((unsigned)time(NULL));

    cout<<randomNum(1, 10)<<endl;
    cout<<randomNum(1, 10)<<endl;
    cout<<randomNum(1, 10)<<endl;

    return 0;
}