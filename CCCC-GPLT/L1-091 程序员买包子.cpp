#include <iostream>
using namespace std;
int main() {
    int N, M, K;
    string X;
    cin >> N >> X >> M >> K;
    if (K == N) cout << "mei you mai " << X << " de";
    else if (K == M) cout << "kan dao le mai " << X << " de";
    else cout << "wang le zhao mai " << X << " de";
    return 0;
}