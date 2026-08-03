#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo *siguiente;
};
void insertar(Nodo *&cabeza, int valor) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo *actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}
void imprimir(Nodo *cabeza) {
    Nodo *actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}
int main() {
    Nodo *lista = nullptr;
    insertar(lista, 10);
    insertar(lista, 20);
    insertar(lista, 30);
    imprimir(lista);
    Nodo *actual = lista;
    while (actual != nullptr) {
        Nodo *temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    return 0;
}