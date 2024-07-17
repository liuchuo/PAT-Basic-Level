#include <iostream>
#include <string>
using namespace std;
string s, a, b, X;
int N, l, r, pos;
int main() {
    cin >> s >> N;
    while (N--) {
        cin >> l >> r >> a >> b;
        X = s.substr(l - 1, r - l + 1);
        s.erase(l - 1, r - l + 1);
        pos = s.find(a + b);
        if (pos == -1) s = s + X;
        else {
            s = s.substr(0, pos + (int)a.size()) + X + s.substr(pos + (int)a.size());
        }
    }
    cout << s;
    return 0;
}