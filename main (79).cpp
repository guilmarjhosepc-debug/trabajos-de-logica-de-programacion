#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << arr[i]
             << " -> direccion: " << &arr[i] << endl;
    }

    long diferencia = (char*)&arr[4] - (char*)&arr[0];
    cout << "Bytes entre el primero y el ultimo: " << diferencia << endl;

    return 0;
}