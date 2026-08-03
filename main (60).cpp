#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 8;
    swap(&x, &y);
    cout << x << " " << y << endl; // 8 5
    return 0;
}