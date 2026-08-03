#include<iostream>
using namespace std;
int main() {
    int escalar=2;
    int A[5]={10,20,30,40,50};
    for (int i=0;i<5;i++) {
        A[i]=A[i]*escalar;}
    for(int i=5;i<5;i++){
    cout<<"A[i]="<<A[i];}
    cout<<endl;
    return 0;
}