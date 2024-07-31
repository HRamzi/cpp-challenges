#include <iostream>
#include <math.h>

using namespace std;

void getTriangleData(float &a, float &b, float &c){
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;
}

float circleAreaByArbitTriangle(float a, float b, float c){

    const float PI = 3.141592653589793238;
    const float P = (a+b+c)/2;
    const float T = (a*b*c)/(4*sqrt(P*(P-a)*(P-b)*(P-c)));

    float area = PI * pow(T,2);

    return area;
}

void printCircleArea(float area){
    cout<<"area of the Circle by Arbitrary Triangle is: "<<area<<endl;
}

int main(){
    float a, b,c;
    getTriangleData(a, b, c);
    printCircleArea(circleAreaByArbitTriangle(a, b, c));

    return 0;
}