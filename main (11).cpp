#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float a,b,area,p;
    cout<<"ingrese el valor de a: ";
    cin>>a;
    cout<<"ingrese el valor de b: ";
    cin>>b;
    area=M_PI*a*b;
    p=2*M_PI*sqrt((a*a+b*b)/2);
    cout<<"el area es: "<<area<<endl;
    cout<<"el perimetro es: "<<p<<endl;
    return 0;
}