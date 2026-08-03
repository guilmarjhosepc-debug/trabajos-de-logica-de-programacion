#include <iostream>
using namespace std;
int main() {
    int n, cont = 0;
    cout<<"escribe una numero: ";
    cin >> n;
    while (n > 0) {
        n = n / 10;  // elimina el último dígito
        cont++;
    }
    cout <<"el numero tiene "<<cont<<" digitos" << endl;
    return 0;
}