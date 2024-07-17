#include <iostream>
using namespace std;
int N, M, Q, T, C, Num_C, Num_R, Column[100001], Row[100001]; 
int main() {
    cin >> N >> M >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> T >> C;
        if (T && !Column[C]) {
            Column[C] = 1;
            ++Num_C;
        } else if (!T && !Row[C]) {
            Row[C] = 1;
            ++Num_R;
        }
    } 
    cout << N * M - Num_C * N - Num_R * M + Num_C * Num_R;
    return 0;
}