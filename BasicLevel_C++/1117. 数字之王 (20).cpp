#include <iostream>
#include <vector>
using namespace std;
int N1, N2, f, A[1005], B[10], maxn;
vector<int> ans;
signed main(){
    cin >> N1 >> N2;
    for (int i = N1; i <= N2; i++) A[i] = i;
    if (N2 > 9) f = 1;
    while (f) {
        f = 0;
        for (int i = N1; i <= N2; i++) {
            if (!A[i]) continue;
            int t1 = 1, t2 = A[i];
            while(t2) {
                t1 *= (t2 % 10) * (t2 % 10) * (t2 % 10);
                t2 /= 10;
            }
            while(t1) {
                t2 += t1 % 10;
                t1 /= 10;
            }
            if (t2 > 9) f = 1;
            A[i] = t2;
        }
    }
    for (int i = N1; i <= N2; i++) {
         B[A[i]]++;
         maxn = max(maxn, B[A[i]]);
    }
    for (int i = 0 ; i < 10; i++) 
        if (B[i] == maxn) ans.push_back(i);
    cout << maxn << '\n';
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    return 0;
}