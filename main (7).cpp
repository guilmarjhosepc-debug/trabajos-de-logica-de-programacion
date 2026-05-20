#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float l,a;
    cout<<"ingrese el lado: ";
    cin>>l;
    a=2*(1+sqrt(2))*l*l;
    cout<<"el area es: "<<a<<endl;
    return 0;
}