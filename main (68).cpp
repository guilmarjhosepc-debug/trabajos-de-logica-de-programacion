#include <iostream>
using namespace std;
int main() {
    int x = 10, y = 20;
    const int *p1 = &x; 
    p1 = &y;        
    int *const p2 = &x;  
    *p2 = 5;             
    const int *const p3 = &x; 
    cout << "x: " << x << endl;
    return 0;
}