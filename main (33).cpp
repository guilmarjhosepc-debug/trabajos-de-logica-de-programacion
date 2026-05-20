#include <iostream>
using namespace std;

int main() {
    // Fila 1: 4 espacios, 1 asterisco
    cout<< "    ";
    for (int i = 0; i < 1; i++) cout << " * ";
    cout << endl;

    // Fila 2: 2 espacios, 3 asteriscos
    cout << "  ";
    for (int i = 0; i < 3; i++) cout << " * ";
    cout << endl;

    // Fila 3: 0 espacios, 5 asteriscos
    for (int i = 0; i < 5; i++) cout << " * ";
    cout << endl;

    // Fila 4: 2 espacios, 3 asteriscos (igual a la fila 2)
    cout << "  ";
    for (int i = 0; i < 3; i++) cout << "* ";
    cout << endl;

    // Fila 5: 4 espacios, 1 asterisco (igual a la fila 1)
    cout << "    ";
    for (int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    return 0;
}