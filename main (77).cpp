#include <iostream>
#include <string>
using namespace std;
struct Persona {
    string nombre;
    int edad;
};
int main() {
    Persona *p = new Persona;
    p->nombre = "Carlos";
    p->edad = 30;
    cout << p->nombre << " tiene " << p->edad << " de edad." << endl;
    delete p;
    p = nullptr;
    return 0;
}