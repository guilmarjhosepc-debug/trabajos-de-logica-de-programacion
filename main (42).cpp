#include<iostream>
using namespace std;
int main(){
    int n,contador=0,grupo=1,num=1;
    cout<<"INGRESE EL VALOR DE N: ";  cin>>n;
    while(contador<n){
        cout<<0;
        contador++;
        if(contador<n) cout<<" , ";
        for(int i=1;i<=grupo&&contador<n;i++){
            cout<<num;
            contador++;
            num++;
            if(contador<n) cout<<" , ";
        }
        grupo++;
    } cout<<endl;
}