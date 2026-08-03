#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int *p = &x;
    int **pp = &p;
    cout << **pp << endl;
    **pp = 100;
    cout << x << endl;
    return 0;
}