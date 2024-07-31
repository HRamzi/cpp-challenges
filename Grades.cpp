#include <iostream>

using namespace std;

int readNumberInRange(int from, int To){

    int grade;

    do
    {
        cout<<"Enter a grade between 0 and 100";
        cin>>grade;
    } while (grade<0 || grade>100);

    return grade;
}

char getGradeLetter(int grade){
    if(grade>=90)
        return 'A';
    else if(grade>=80)
        return 'B';
    else if(grade>=70)
        return 'C';
    else if(grade>=60)
        return 'D';
    else if(grade>=50)
        return 'E';
    else
        return 'F';
}

int main(){

    cout<<endl<<"result: "<<getGradeLetter(readNumberInRange(0, 100));

    return 0;
}