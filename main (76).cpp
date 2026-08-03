#include <iostream>
using namespace std;
int* buscar(int *arr, int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            return &arr[i];
        }
    }
    return nullptr;
}
int main() {
    int arr[5] = {10, 25, 30, 45, 50};
    int *resultado = buscar(arr, 5, 30);

    if (resultado != nullptr) {
        cout << "Encontrado: " << *resultado << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    return 0;
}