#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float r,h,v;
    cout<<"ingrese el radio: ";
    cin>>r;
    cout<<"ingrese la altura: ";
    cin>>h;
    v=(M_PI*r*r*h)/3;
    cout<<"el volumen del cono es: "<<v<<endl;
    return 0;
}