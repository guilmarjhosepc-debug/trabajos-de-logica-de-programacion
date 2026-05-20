#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    int a,i,j,k,p;
    
    cout<<"ingrese el numero de filas: "; cin>>a;
    
                    cout<<"7)"<<endl;
        for(i=1;i<=a;i++){
            for(j=1;j<=a;j++){
                if(i==1||i==a||j==i){
                    cout<<"* ";
                } else {
                    cout<<"  ";}
                } cout<<endl; }
}