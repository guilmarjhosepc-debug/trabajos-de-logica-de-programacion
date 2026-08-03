#include <iostream>
#include <string>
using namespace std;
const int TAM_TABLA = 5;
struct Empleado {
    int id;
    string nombre;
};
struct Nodo {
    Empleado dato;
    Nodo *siguiente;
};
int funcionHash(int id) {
    return id % TAM_TABLA;
}
void insertar(Nodo **tabla, int id, string nombre) {
    int indice = funcionHash(id);

    Nodo *nuevo = new Nodo;
    nuevo->dato.id = id;
    nuevo->dato.nombre = nombre;
    nuevo->siguiente = tabla[indice];
    tabla[indice] = nuevo;
}
Nodo* buscar(Nodo **tabla, int id) {
    int indice = funcionHash(id);
    Nodo *actual = tabla[indice];
    while (actual != nullptr) {
        if (actual->dato.id == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}
void liberarTabla(Nodo **tabla) {
    for (int i = 0; i < TAM_TABLA; i++) {
        Nodo *actual = tabla[i];
        while (actual != nullptr) {
            Nodo *temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
        tabla[i] = nullptr;
    }
}
void imprimirTabla(Nodo **tabla) {
    for (int i = 0; i < TAM_TABLA; i++) {
        cout << "[" << i << "]: ";
        Nodo *actual = tabla[i];
        while (actual != nullptr) {
            cout << "(" << actual->dato.id << ", " << actual->dato.nombre << ") -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }
}
int main() {
    Nodo **tabla = new Nodo*[TAM_TABLA];
    for (int i = 0; i < TAM_TABLA; i++) {
        tabla[i] = nullptr;
    }
    insertar(tabla, 3, "Ana");
    insertar(tabla, 8, "Luis");
    insertar(tabla, 1, "Marta");
    insertar(tabla, 12, "Pedro");
    cout << "--- Tabla hash ---" << endl;
    imprimirTabla(tabla);
    cout << "\n--- Busquedas ---" << endl;
    int idBuscar = 8;
    Nodo *resultado = buscar(tabla, idBuscar);
    if (resultado != nullptr) {
        cout << "Encontrado: id=" << resultado->dato.id
             << ", nombre=" << resultado->dato.nombre << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    idBuscar = 99;
    resultado = buscar(tabla, idBuscar);
    if (resultado != nullptr) {
        cout << "Encontrado: id=" << resultado->dato.id << endl;
    } else {
        cout << "ID " << idBuscar << " no encontrado" << endl;
    }
    liberarTabla(tabla);
    delete[] tabla;
    return 0;
}