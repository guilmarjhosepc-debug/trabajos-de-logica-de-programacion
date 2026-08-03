#include <iostream>
using namespace std;
const int FILAS = 2;
const int COLS = 3;
int sumarMatriz(int (*matriz)[COLS], int filas) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < COLS; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}
int main() {
    int matriz[FILAS][COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Suma total: " << sumarMatriz(matriz, FILAS) << endl;
    return 0;
}