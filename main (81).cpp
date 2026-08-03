#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Cuantos elementos? ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    int buscado;
    cout << "Valor a buscar: ";
    cin >> buscado;

    int *encontrado = nullptr;
    for (int *p = arr; p < arr + n; p++) {
        if (*p == buscado) {
            encontrado = p;
            break;
        }
    }

    if (encontrado != nullptr) {
        cout << "Encontrado en posicion: " << (encontrado - arr) << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    delete[] arr;
    arr = nullptr;
    return 0;
}