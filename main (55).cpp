#include<iostream>
using namespace std;
int main() {
    int indice=-1;
    int A[5]={10,20,40,50,30};
    int mayor=A[0];
    int posicion=0;
    int suma=0;
    int menor=A[0];
     for (int i=1;i<5;i++) {
        if (A[i]>mayor) {
            mayor=A[i];}
            for (int i=1;i<5;i++) {
        if (A[i]<menor) {
            menor=A[i]; }
    suma=menor+mayor;}
     }
    cout<<"El numero mayor es: "<<mayor<<endl;
    cout<<"El numero menor es: "<<menor<<endl;
    cout<<"la suma es: "<<suma<<endl;
    return 0;
}