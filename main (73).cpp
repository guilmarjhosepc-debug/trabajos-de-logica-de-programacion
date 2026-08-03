#include <iostream>
using namespace std;
int main() {
    int entero = 10;
    double flotante = 3.14;
    void *ptr;
    ptr = &entero;
    cout << "Entero: " << *(int*)ptr << endl;
    ptr = &flotante;
    cout << "Flotante: " << *(double*)ptr << endl;
    return 0;
}