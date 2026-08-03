#include <iostream>
using namespace std;
int* crearPuntero() {
    int *x = new int(10);
    return x;
}
int main() {
    int *p = crearPuntero();
    cout << *p << endl; 
    delete p;
    return 0;
}