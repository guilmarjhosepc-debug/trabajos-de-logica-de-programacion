#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    int a,i,j,k,p;
    
    cout<<"ingrese el numero de filas: "; cin>>a;
   
             cout<<"10)"<<endl;
            for(i=a;i>=1;i-=2) {
        p=(a-i)/2;
        for(j=1; j<=p;j++) {
            cout<<"  ";}
        for(j=1;j<=i;j++) {
            cout<<"* "; }
        cout<<endl;}
    for(i=3;i<=a;i+=2) {
        p=(a-i)/2;
        for(j=1;j<=p;j++) {
            cout<<"  ";}
        for(j=1;j<=i;j++) {
            cout<<"* ";}
        cout << endl;}
}