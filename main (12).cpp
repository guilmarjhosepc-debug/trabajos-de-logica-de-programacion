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
    v=l*a*h;
    cout<<"el volumen es: "<<v<<endl;
    return 0;
}