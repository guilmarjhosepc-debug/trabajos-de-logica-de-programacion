#include<iostream>
using namespace std;
int main(){
    int n,cuadrado,suma=0;
    cout<<"ingrese un numero: "; cin>>n;
    for(int i=0;i<=n;++i) {
    cuadrado=i*i;
        if(i%2==0){
            suma+=cuadrado;
        } else {
            suma-=cuadrado;
        }
    cout<<suma<<endl;}
    
    return 0;
}