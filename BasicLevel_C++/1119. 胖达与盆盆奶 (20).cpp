#include <iostream>
using namespace std;
int n, ans, A[10005], L[10005], R[10005];
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i < n; i++) {
        int j = i;
        while(j + 1 <= n && A[j] >= A[j + 1]) {
            if (A[j] > A[j + 1]) ++L[i];
            ++j;
        }
    }
    for (int i = n; i > 1; i--) {
        int j = i;
        while(j - 1 >= 1 && A[j] >= A[j - 1]) {
            if (A[j] > A[j - 1]) ++R[i];
            --j;
        }
    }
    for (int i = 1; i <= n; i++) ans += max(L[i], R[i]) * 100 + 200;
    cout << ans;
    return 0;
}