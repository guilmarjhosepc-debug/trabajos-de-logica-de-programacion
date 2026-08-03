#include <iostream>
using namespace std;
void duplicarPuntero(int *n) {
    *n = *n * 2;
}
void duplicarReferencia(int &n) {
    n = n * 2;
}
int main() {
    int a = 5, b = 5;
    duplicarPuntero(&a);   
    duplicarReferencia(b); 
    cout << "a: " << a << ", b: " << b << endl;
    return 0;
}