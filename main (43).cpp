#include <iostream>
using namespace std;
int main () {
    int n,x;
    double st=0;
    cout<<"ingrese x: "; cin>>x;
    cout<<"ingrese los N terminos: "; cin>>n;
    for(int i=1;i<=n;i++) {
    double exponente=1;
    for(int k=1;k<=i;k++){
        exponente*=x;}
        double factorial=1;
        for(int k=1;k<=(2*i-1);k++)
        factorial*=k;
        if(i%2==0){
            st-=exponente/factorial;
        } else {
            st+=exponente/factorial; }
    }
        cout<<"ST=: "<<st<<endl;
    return 0;  
}