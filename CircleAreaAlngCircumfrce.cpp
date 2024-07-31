#include <iostream>
#include <math.h>

using namespace std;

float getCircumference(){
    float l;
    cout<<"L: ";
    cin>>l;
    return l;
}

float circleAreaByCircumference(float l){

    const float PI = 3.141592653589793238;

    float area = pow(l,2)/(4*PI);

    return area;
}

void printCircleArea(float area){
    cout<<"area of the Circle By Circumference is: "<<area<<endl;
}

int main(){

    printCircleArea(circleAreaByCircumference(getCircumference()));

    return 0;
}