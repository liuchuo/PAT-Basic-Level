#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, a, b;
string A, B;
int main() {
    cin >> N;
    while(N--) {
        cin >> A >> B;
        a = b = 0;
        for (auto it : A) {
            a += it - '0';
        }
        for (auto it : B) {
            b += it - '0';
        }
        if (stoi(A) % b == 0 && stoi(B) % a != 0) cout << "A\n";
        else if (stoi(A) % b != 0 && stoi(B) % a == 0) cout << "B\n";
        else if (stoi(A) > stoi(B)) cout << "A\n";
        else cout << "B\n";
    }
    return 0;
}