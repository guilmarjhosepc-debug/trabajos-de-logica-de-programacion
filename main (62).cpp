#include <iostream>
using namespace std;

int sumar(int *arr, int n) {
    int suma = 0;
    for (int *p = arr; p < arr + n; p++) {
        suma += *p;
    }
    return suma;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Suma: " << sumar(arr, 5) << endl;
    return 0;
}