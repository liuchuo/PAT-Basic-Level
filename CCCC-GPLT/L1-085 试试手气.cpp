#include <iostream>
using namespace std;
int n, dice[6];
int main() {
    for (int i = 0; i < 6; i++) cin >> dice[i];
    cin >> n;
    for (int i = 0; i < 6; i++) {
        if (i) cout << ' ';
        if (dice[i] >= 7 - n) cout << 6 - n;
        else cout << 7 - n;
    }
    return 0;
}