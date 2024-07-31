#include <iostream>
#include <math.h>

using namespace std;

void getTriangleData(float &a, float &b){
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
}

float circleAreaByTriangle(float a, float b){

    const float PI = 3.141592653589793238;

    float area = PI * (pow(b,2)/4) * ((2*a-b)/(2*a+b));

    return area;
}

void printCircleArea(float area){
    cout<<"area of the Circle inscribed in isosceles Triangle is: "<<area<<endl;
}

int main(){
    float a, b;
    getTriangleData(a, b);
    printCircleArea(circleAreaByTriangle(a, b));

    return 0;
}