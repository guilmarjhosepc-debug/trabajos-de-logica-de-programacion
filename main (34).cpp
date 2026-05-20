#include <iostream>

using namespace std;

int main() {
    // Fila 1: 4 espacios, 1 asterisco, 12 espacios, 1 asterisco
    cout << "   ";
    for (int i = 0; i < 1; i++) cout << " * ";
    cout << "         "; // 12 espacios (puedes dejarlo en blanco "            ")
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    // Fila 2: 2 espacios, 2 asteriscos, 8 espacios, 2 asteriscos
    cout << "  ";
    for (int i = 0; i < 2; i++) cout << "* ";
    cout << "         ";
    for (int i = 0; i < 2; i++) cout << "* ";
    cout << endl;

    // Fila 3: 0 espacios, 3 asteriscos, 4 espacios, 3 asteriscos
    for (int i = 0; i < 3; i++) cout << "* ";
    cout << "         ";
    for (int i = 0; i < 3; i++) cout << "* ";
    cout << endl;

    // Fila 4: Es igual a la Fila 2
    cout << "  ";
    for (int i = 0; i < 2; i++) cout << "* ";
    cout << "         ";
    for (int i = 0; i < 2; i++) cout << "* ";
    cout << endl;

    // Fila 5: Es igual a la Fila 1
    cout << "    ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << "         "; // Cambia los guiones de la fila 1 por espacios aquí si prefieres vacío
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    return 0;
}