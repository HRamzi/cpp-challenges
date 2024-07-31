#include <iostream>
#include <math.h>

using namespace std;

void readNums(float &a, float &d){
    cout<<"a: ";
    cin>>a;

    cout<<"d: ";
    cin>>d;
}

float calcAreaRectangle(float a, float d){
    return a*sqrt( pow(d,2) - pow(a,2) );
}

void printAreaRectangle(float area){
    cout<<"area of the Rectangle through diagonal is: "<<area<<endl;
}

int main(){
    float a, d;
    readNums(a, d);
    printAreaRectangle(calcAreaRectangle(a, d));

    return 0;
}