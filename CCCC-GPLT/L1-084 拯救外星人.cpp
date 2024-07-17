#include <iostream>
using namespace std;
int A, B, C = 1;
int main() {
    cin >> A >> B;
    for (int i = 1; i <= A + B; i++) {
        C *= i;
    }
    cout << C; 
    return 0;
}