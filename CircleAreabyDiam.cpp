#include <iostream>
#include <math.h>

using namespace std;

float getDiameter(){
    float d;
    cout<<"d: ";
    cin>>d;
    return d;
}

float circleAreaByDiameter(float d){

    const float PI = 3.141592653589793238;

    float area = (PI*pow(d,2))/4;

    return area;
}

void printCircleArea(float area){
    cout<<"area of the Circle By Diameter is: "<<area<<endl;
}

int main(){

    printCircleArea(circleAreaByDiameter(getDiameter()));

    return 0;
}