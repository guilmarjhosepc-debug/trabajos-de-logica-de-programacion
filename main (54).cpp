#include<iostream>
using namespace std;
int main() {
    int indice=-1;
    int A[5]={10,20,40,50,30};
    int n=5;
    int mayor=A[0];
    int posicion=0;
     for (int i=1;i<n;i++) {
        if (A[i]>mayor) {
            mayor=A[i]; 
            posicion=i;}
    }cout<<"Vector: ";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    cout<<"El numero mayor es: "<<mayor<<endl;
    cout<<"Se encuentra en la posicion: "<<posicion;
    return 0;
}