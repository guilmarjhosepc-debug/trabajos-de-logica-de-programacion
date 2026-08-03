#include <iostream>
using namespace std;
void invertir(int *arr, int n) {
    int *inicio = arr;
    int *fin = arr + n - 1;
    while (inicio < fin) {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++;
        fin--;
    }
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    invertir(arr, 5);
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl; // 5 4 3 2 1
    return 0;
}