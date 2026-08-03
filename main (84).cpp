#include <iostream>
using namespace std;
int main() {
    int x = 10;
    int y = 10;
    int *p1 = &x;
    int *p2 = &y;
    int *p3 = &x;
    cout << "Valores iguales (*p1 == *p2)? " << (*p1 == *p2) << endl; 
    cout << "Direcciones iguales (p1 == p2)? " << (p1 == p2) << endl; 
    cout << "Direcciones iguales (p1 == p3)? " << (p1 == p3) << endl; 
    return 0;
}