#include <iostream>

using namespace std;

int main() {
    // Fila 1: Línea superior completa (7 asteriscos seguidos)
    for (int i = 0; i < 7; i++) {
        cout << "* ";
    }
    cout << endl;

    // Fila 2: 2 espacios de margen, 1 asterisco, 6 espacios internos, 1 asterisco
    cout << "  ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << "      "; 
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    // Fila 3: 4 espacios de margen, 1 asterisco, 2 espacios internos, 1 asterisco
    cout << "    ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << "  "; 
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    // Fila 4: 6 espacios de margen, 1 asterisco (la punta inferior)
    cout << "      ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    return 0;
}