#include <iostream>

using namespace std;

void readNums(float &a, float &b){
    cout<<"a: ";
    cin>>a;

    cout<<"b: ";
    cin>>b;
}

float calcAreaRectangle(float a, float b){
    return a*b;
}

void printAreaRectangle(float area){
    cout<<"area of the Rectangle is: "<<area<<"m²"<<endl;
}

int main(){
    float a, b;
    readNums(a, b);
    printAreaRectangle(calcAreaRectangle(a, b));

    return 0;
}