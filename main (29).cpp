#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    int a,i,j,k,p;
    
    cout<<"ingrese el numero de filas: "; cin>>a;
    
                cout<<"8)"<<endl;
                for(i=1;i<=a;i++){
        for(j=1;j<=a-i;j++){
            cout<<"  ";}
            for(k=1;k<=i;k++){
                cout<<"* ";}
            cout<<endl;}
}