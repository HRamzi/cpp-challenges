#include <iostream>

using namespace std;

void readNums(float &a, float &h){
    cout<<"a: ";
    cin>>a;

    cout<<"h: ";
    cin>>h;
}

float calcAreaRectangle(float a, float h){
    return (a/2)*h;
}

void printAreaRectangle(float area){
    cout<<"area of the Rectangle is: "<<area<<endl;
}

int main(){
    float a, h;
    readNums(a, h);
    printAreaRectangle(calcAreaRectangle(a, h));

    return 0;
}