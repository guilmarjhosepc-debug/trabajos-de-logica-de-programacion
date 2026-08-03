#include <iostream>
using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int main() {
    int (*ptrFunc)(int, int) = sumar;
    cout << ptrFunc(3, 4) << endl; // 7
    return 0;
}