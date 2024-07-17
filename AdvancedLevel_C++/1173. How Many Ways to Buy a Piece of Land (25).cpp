#include <iostream>
using namespace std;
int N, M, ans, a, pre[10005];
int main(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a;
        pre[i] = pre[i - 1] + a;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (pre[j] - pre[i - 1] <= M) ++ans;
            else break;
        }
    }
    cout << ans;
    return 0;
}