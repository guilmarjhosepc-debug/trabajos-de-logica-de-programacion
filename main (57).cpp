#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Ingrese la cantidad de datos: ";
    cin>>n;
    double datos[100],suma=0;
    for (int i = 0; i<n;i++) {
        cout <<"x["<< i+1 << "] = ";
        cin >> datos[i];
        suma += datos[i];
    }
    double media = suma/n;
    cout<<"Media Aritmetica = "<<media<<endl;
    return 0;
}