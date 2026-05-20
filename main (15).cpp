#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float r,v;
    cout<<"ingrese el radio: ";
    cin>>r;
    v=(4.0/3.0)*M_PI*r*r*r;
    cout<<"el volumen es: "<<v<<endl;
    return 0;
}