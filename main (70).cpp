#include <iostream>
using namespace std;
int longitud(const char *str) {
    int contador = 0;
    while (*str != '\0') {
        contador++;
        str++;
    }
    return contador;
}
int main() {
    const char *texto = "Hola mundo";
    cout << "Longitud: " << longitud(texto) << endl;
    return 0;
}