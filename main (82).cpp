#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo *siguiente;
};
Nodo* buscarNodo(Nodo *cabeza, int valor) {
    Nodo *actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}
int main() {
    Nodo *n3 = new Nodo{30, nullptr};
    Nodo *n2 = new Nodo{20, n3};
    Nodo *n1 = new Nodo{10, n2};
    Nodo *resultado = buscarNodo(n1, 20);
    if (resultado != nullptr) {
        cout << "Nodo encontrado con valor: " << resultado->dato << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    delete n1; delete n2; delete n3;
    return 0;
}