#include <iostream>

using namespace std;

int main() {
    // Fila 1: 4 espacios de margen, 1 asterisco, 8 espacios internos, 1 asterisco
    cout << "    ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << "        ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    // Fila 2: 6 espacios de margen, 1 asterisco, 4 espacios internos, 1 asterisco
    cout << "      ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << "    ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    // Fila 3: 8 espacios de margen, 1 asterisco (el centro)
    cout << "         ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    // Fila 4: Igual a la Fila 2
    cout << "      ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << "    ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    // Fila 5: Igual a la Fila 1
    cout << "    ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << "        ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    return 0;
}