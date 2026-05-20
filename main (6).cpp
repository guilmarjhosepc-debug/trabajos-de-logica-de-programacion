#include <iostream>
using namespace std;

int main(){
    float b1,b2,h,a;
    cout<<"ingrese la base mayor: ";
    cin>>b1;
    cout<<"ingrese la base menor: ";
    cin>>b2;
    cout<<"ingrese la altura: ";
    cin>>h;
    a=((b1+b2)*h)/2;
    cout<<"el area es: "<<a<<endl;
    return 0;
}