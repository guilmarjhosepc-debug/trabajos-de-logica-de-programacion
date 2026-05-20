#include <iostream>
using namespace std;

int main(){
    float l,a,h,v;
    cout<<"ingrese el largo: ";
    cin>>l;
    cout<<"ingrese el ancho: ";
    cin>>a;
    cout<<"ingrese la altura: ";
    cin>>h;
    v=(l*a*h)/0.8;
    cout<<"el volumen de la caja rectangular es: "<<v<<endl;
    return 0;
}