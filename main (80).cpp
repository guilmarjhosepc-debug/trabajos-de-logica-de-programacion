#include <iostream>
using namespace std;

int* buscarMaximo(int *arr, int n) {
    int *maximo = arr;
    for (int *p = arr + 1; p < arr + n; p++) {
        if (*p > *maximo) {
            maximo = p;
        }
    }
    return maximo;
}

int main() {
    int arr[6] = {12, 45, 3, 89, 34, 67};
    int *max = buscarMaximo(arr, 6);

    cout << "Valor maximo: " << *max << endl;
    cout << "Posicion: " << (max - arr) << endl;
    return 0;
}