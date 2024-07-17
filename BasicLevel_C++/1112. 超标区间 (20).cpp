#include <iostream>
using namespace std;
int N, T, maxn, A[10005];
int main(){
    cin >> N >> T;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        maxn = max(maxn, A[i]);
        if (A[i] <= T) continue;
        int end = i;
        while(end + 1 < N && A[end + 1] > T) ++end;
        cout << "[" << i << ", " << end << "]\n";
        i = end;
    }
    if (maxn <= T) cout << maxn;
    return 0;
}