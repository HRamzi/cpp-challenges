#include <iostream>
#include <math.h>

using namespace std;

float getRadious(){

    float r;

    cout<<"r: ";
    cin>>r;

    return r;
}

float calcCircleArea(float r){

    const float PI = 3.141592653589793238;

    float area = PI*pow(r,2);

    return area;
}

void printCircleArea(float area){

    cout<<"area of the Circle is: "<<area<<endl;
}

int main(){

    printCircleArea(calcCircleArea(getRadious()));

    return 0;
}