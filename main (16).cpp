#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float x,y,z,r;
    cout<<"ingrese el valor de x: ";
    cin>>x;
    cout<<"ingrese el valor de y: ";
    cin>>y;
    cout<<"ingrese el valor de z: ";
    cin>>z;
    r=((2*x+y)/z)*(pow(y,3)-z)/((x+2*y+3*z)/(z-2*y-3*x)+x*x+z*z);
    cout<<"el resultado es: "<<r<<endl;
    return 0;
}