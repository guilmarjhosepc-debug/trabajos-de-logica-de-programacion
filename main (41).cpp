#include<iostream>
using namespace std;
int main() {
    int n=8;
    int a=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a;j++){
            cout<<j<<" , ";
        }
        for(int k=a;k>=1;k--){
            cout<<k<<" , ";
        }
        a=a-1;
    }
}   