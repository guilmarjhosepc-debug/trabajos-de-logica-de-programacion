#include <iostream>

using namespace std;

int main() {
    // Fila 1: 1 asterisco, 8 espacios, 1 asterisco
    for(int i = 0; i < 1; i++) cout << "* ";
    cout << "        "; 
    for(int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    // Fila 2: 2 asteriscos, 4 espacios, 2 asteriscos
    for(int i = 0; i < 2; i++) cout << "* ";
    cout << "    "; 
    for(int i = 0; i < 2; i++) cout << "* ";
    cout << endl;

    // Fila 3: Toda la fila llena (6 asteriscos seguidos)
    for(int i = 0; i < 6; i++) {
        cout << "* ";
    }
    cout << endl;

    // Fila 4: Es igual a la Fila 2
    for(int i = 0; i < 2; i++) cout << "* ";
    cout << "    "; 
    for(int i = 0; i < 2; i++) cout << "* ";
    cout << endl;

    // Fila 5: Es igual a la Fila 1
    for(int i = 0; i < 1; i++) cout << "* ";
    cout << "        "; 
    for(int i = 0; i < 1; i++) cout << "* ";
    cout << endl;

    return 0;
}