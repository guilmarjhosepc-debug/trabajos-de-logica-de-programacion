#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float r,h,v;
    cout<<"ingrese el radio: ";
    cin>>r;
    cout<<"ingrese la altura: ";
    cin>>h;
    v=M_PI*r*r*h;
    cout<<"el volumen es: "<<v<<endl;
    return 0;
}