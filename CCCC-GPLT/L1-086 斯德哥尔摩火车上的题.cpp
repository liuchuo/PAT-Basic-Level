#include <iostream>
using namespace std;
string s, a, S = "", A = "";
int main() {
    cin >> s >> a;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] % 2 == s[i - 1] % 2) S += max(s[i], s[i - 1]);
    }
    for (int i = 1; i < a.size(); i++) {
        if (a[i] % 2 == a[i - 1] % 2) A += max(a[i], a[i - 1]);
    }
    cout << S;
    if (S != A) cout << '\n' << A; 
    return 0;
}