#include <iostream>
using namespace std;
int N, K, S, ans, score_gplt, score_pat, mark[10001];
int main() {
    cin >> N >> K >> S;
    for (int i = 0; i < N; i++) {
        cin >> score_gplt >> score_pat;
        if (score_gplt >= 175) {
            if (score_pat >= S) ++ans;
            else if (mark[score_gplt] < K) {
                ans++;
                mark[score_gplt]++;
            }
        }
    }
    cout << ans;
    return 0;
}