#include <iostream>
#include <math.h>

using namespace std;

float getSquareSides(){
    float A;
    cout<<"A: ";
    cin>>A;
    return A;
}

float circleAreaInscribedInSquare(float A){

    const float PI = 3.141592653589793238;

    float area = (PI*pow(A,2))/4;

    return area;
}

void printCircleArea(float area){
    cout<<"area of the Circle By Diameter is: "<<area<<endl;
}

int main(){

    printCircleArea(circleAreaInscribedInSquare(getSquareSides()));

    return 0;
}