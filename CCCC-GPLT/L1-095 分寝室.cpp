#include <iostream>
using namespace std;
int n0, n1, n, F, M;
int main() {
    cin >> n0 >> n1 >> n;
    for (int i = 2; i <= n0; i++) {
        if (n0 % i != 0 || n0 / i > n) continue;
        int j = n - n0 / i;
        if (n1 % j != 0) continue;
        if (!F || abs(i - n1 / j) < abs(n0 / F - n1 / M)) {
            F = n0 / i, M = j;
        }
    }
    if (F) cout << F << ' ' << M;
    else cout << "No Solution";
    return 0;
}