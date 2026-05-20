#include <iostream>
using namespace std;

int main(){
    float l,h1,h2,vp,vpi,vt;
    cout<<"ingrese el lado: ";
    cin>>l;
    cout<<"ingrese la altura del paralelepipedo: ";
    cin>>h1;
    cout<<"ingrese la altura de la piramide: ";
    cin>>h2;
    vp=l*l*h1;
    vpi=(l*l*h2)/3;
    vt=vp-vpi;
    cout<<"el volumen del paralelepipedo es: "<<vp<<endl;
    cout<<"el volumen de la piramide es: "<<vpi<<endl;
    cout<<"el volumen total es: "<<vt<<endl;
    return 0;
}