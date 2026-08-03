#include <iostream>
using namespace std;
const int FILAS = 3;
const int COLS = 3;
bool buscarEnMatriz(int (*matriz)[COLS], int filas, int valor, int &fila, int &col) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < COLS; j++) {
            if (*(*(matriz + i) + j) == valor) {
                fila = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
int main() {
    int matriz[FILAS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int fila, col;
    if (buscarEnMatriz(matriz, FILAS, 5, fila, col)) {
        cout << "Encontrado en fila " << fila << ", columna " << col << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    return 0;
}