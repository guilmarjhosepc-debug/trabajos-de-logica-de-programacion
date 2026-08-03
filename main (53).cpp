#include<iostream>
using namespace std;
int main() {
    int busca=50;
    int indice=-1;
    int A[5]={10,20,30,40,50};
    for (int i=0;i<5;i++) {
    if(A[i]==busca){
        indice=i;}
        if(indice!=-1){
        cout<<"el elemento se encontro "<<i;
        }else{
            cout<<"no se encontro";
        }
    }
    return 0;
}