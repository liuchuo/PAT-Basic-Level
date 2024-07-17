#include <iostream>
using namespace std;
int N, A[1005], B[1005], a, b, c, num, mt;
int main() {
    cin >> N;
    while (N--) {
        cin >> c;
        if (a == 0 || A[a] > c) {
            A[++a] = c;
        } else if (b == 0 || B[b] < c) {
            B[++b] = c;
        } else {
            mt = max(mt, a);
            a = 0;
            num++;
            while (b && B[b] > c) {
                A[++a] = B[b--];
            }
            A[++a] = c;
        }
    }
    mt = max(mt, a);
    if (b) ++num;
    cout << num + 1 << ' ' << mt;
    return 0;
}