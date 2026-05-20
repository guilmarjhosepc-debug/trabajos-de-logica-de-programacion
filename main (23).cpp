#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    int a,i,j,k,p;
    
    cout<<"ingrese el numero de filas: "; cin>>a;
    cout<<"2)"<<endl;
    for(i=0;i<a;i++){
        for(j=0;j<a;j++){
            if((i==0)||(j==0)||(i==a-1)||(j==a-1)) {
            cout<<"* ";} else {
            cout<<"  ";}
    } cout<<"\n"; }  
}