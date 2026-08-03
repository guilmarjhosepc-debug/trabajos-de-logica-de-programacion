#include <iostream>
using namespace std;
int main() {
    int n, i = 1;
    cout<<"ingrese un valor: ";
    cin >> n;
    while (i <= 100) {
        cout << n << " x " << i << " = " << n * i << endl;
        i++;
    }
    return 0;
}