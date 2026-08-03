#include <iostream>
using namespace std;

int* busquedaBinaria(int *arr, int n, int valor) {
    int *inicio = arr;
    int *fin = arr + n - 1;

    while (inicio <= fin) {
        int *medio = inicio + (fin - inicio) / 2;

        if (*medio == valor) {
            return medio;
        } else if (*medio < valor) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return nullptr;
}

int main() {
    int arr[8] = {2, 5, 8, 12, 16, 23, 38, 45};
    int *resultado = busquedaBinaria(arr, 8, 23);

    if (resultado != nullptr) {
        cout << "Encontrado: " << *resultado << endl;
        cout << "Posicion (indice): " << (resultado - arr) << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    return 0;
}