#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float r,h,ve,vc,vt;
    cout<<"ingrese el radio: ";
    cin>>r;
    cout<<"ingrese la altura del cilindro: ";
    cin>>h;
    ve=(4.0/3.0)*M_PI*r*r*r;
    vc=M_PI*r*r*h;
    vt=ve+vc;
    cout<<"el volumen de la esfera es: "<<ve<<endl;
    cout<<"el volumen del cilindro es: "<<vc<<endl;
    cout<<"el volumen total es: "<<vt<<endl;
    return 0;
}