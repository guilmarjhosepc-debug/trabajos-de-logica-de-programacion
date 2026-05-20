#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, h;
    cout << "ingrese el cateto a: ";
    cin >> a;
    cout << "ingrese el cateto b: ";
    cin >> b;
    h = sqrt(a*a + b*b);
    cout << "la hipotenusa es: " << h << endl;
    return 0;
}