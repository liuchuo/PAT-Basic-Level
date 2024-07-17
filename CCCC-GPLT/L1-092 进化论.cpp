#include <iostream>
using namespace std;
int main() {
    int N, A, B, C;
    cin >> N;
    while(N--) {
        cin >> A >> B >> C;
        if (C == A * B) cout << "Lv Yan\n";
        else if (C == A + B) cout << "Tu Dou\n";
        else cout << "zhe du shi sha ya!\n";
    }
    return 0;
}