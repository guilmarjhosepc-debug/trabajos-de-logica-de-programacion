#include <iostream>
using namespace std;

int main(){
    float l,a,p,ap;
    cout<<"ingrese el lado: ";
    cin>>l;
    cout<<"ingrese el apotema: ";
    cin>>ap;
    p=5*l;
    a=(p*ap)/2;
    cout<<"el area es: "<<a<<endl;
    cout<<"el perimetro es: "<<p<<endl;
    return 0;
}