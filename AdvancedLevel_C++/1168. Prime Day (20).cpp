#include <iostream>
#include <cmath>
using namespace std;
int num;
string s;
int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return 0;
    return 1;
}
int main(){
    cin >> s;
    num = s.size();
    while (s.size()) {
        cout << s << ' ' << (is_prime(stoi(s)) ? "Yes" : "No") << '\n';
        if (is_prime(stoi(s))) --num;
        s.erase(s.begin());
    }
    if (num == 0) cout << "All Prime!";
    return 0;
}