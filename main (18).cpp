#include <iostream>
using namespace std;

int main(){
    float l,a,h1,h2,vp,vpi,vt;
    cout<<"ingrese el largo: ";
    cin>>l;
    cout<<"ingrese el ancho: ";
    cin>>a;
    cout<<"ingrese la altura del paralelepipedo: ";
    cin>>h1;
    cout<<"ingrese la altura de la piramide: ";
    cin>>h2;
    vp=l*a*h1;
    vpi=(l*a*h2)/3;
    vt=vp+vpi;
    cout<<"el volumen del paralelepipedo es: "<<vp<<endl;
    cout<<"el volumen de la piramide es: "<<vpi<<endl;
    cout<<"el volumen total es: "<<vt<<endl;
    return 0;
}