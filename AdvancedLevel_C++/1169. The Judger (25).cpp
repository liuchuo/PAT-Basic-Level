#include <iostream>
#include <vector>
using namespace std;
int N, M, flag2, A[11][1001], mark[200005], out[11];
vector<int> used(2);
int main(){
    cin >> used[0] >> used[1];
    mark[used[0]] = mark[used[1]] = 1;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) cin >> A[i][j];
    for (int i = 1; i <= M; i++) 
        for (int j = 1; j <= N; j++) {
            if (out[j]) continue;
            int flag = 0;
            if (mark[A[j][i]]) flag = -1;
            for (auto it : used) {
                if (mark[it + A[j][i]] == 1) {
                    mark[A[j][i]] = 1;
                    flag++;
                    used.push_back(A[j][i]);
                    break;
                }
            }
            if (flag <= 0) {
                out[j] = 1;
                cout << "Round #" << i << ": " << j << " is out.\n";
            }
        }
    for (int i = 1; i <= N; i++) {
        if (!out[i]) {
            if(!flag2) {
                cout << "Winner(s):";
                flag2 = 1;
            }
            cout << " " << i;
        }
    }
    if (!flag2) cout << "No winner.";
    return 0;
}