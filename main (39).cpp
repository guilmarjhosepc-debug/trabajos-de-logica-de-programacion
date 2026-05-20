#include <iostream>
using namespace std;

int main(){
    int op;
    float a,b,r;
    cout<<"=== CALCULADORA ==="<<endl;
    cout<<"1. Suma"<<endl;
    cout<<"2. Resta"<<endl;
    cout<<"3. Multiplicacion"<<endl;
    cout<<"4. Division"<<endl;
    cout<<"ingrese la opcion: ";
    cin>>op;
    cout<<"ingrese el valor de a: ";
    cin>>a;
    cout<<"ingrese el valor de b: ";
    cin>>b;
    switch(op){
        case 1:
            r=a+b;
            cout<<"el resultado es: "<<r<<endl;
            break;
        case 2:
            r=a-b;
            cout<<"el resultado es: "<<r<<endl;
            break;
        case 3:
            r=a*b;
            cout<<"el resultado es: "<<r<<endl;
            break;
        case 4:
            r=a/b;
            cout<<"el resultado es: "<<r<<endl;
            break;
        default:
            cout<<"opcion invalida"<<endl;
            break;
    }
    return 0;
}