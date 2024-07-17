#include <iostream>
using namespace std;
int k, w, lost[19][1 << 18], win[19][1 << 18], ans[1 << 18];
int main() {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < (1 << (k - i)); j++) {
            cin >> lost[i][j];
            if (i == 1) {
                ans[j << 1] = lost[i][j];
                win[i][j] = j << 1 | 1;
            } else {
                if (lost[i][j] < lost[i - 1][j << 1] && lost[i][j] < lost[i - 1][j << 1 | 1]) {
                    cout << "No Solution";
                    return 0;
                } else if (lost[i][j] >= lost[i - 1][j << 1]) {
                    ans[win[i - 1][j << 1]] = lost[i][j];
                    win[i][j] = win[i - 1][j << 1 | 1];
                } else {
                    ans[win[i - 1][j << 1 | 1]] = lost[i][j];
                    win[i][j] = win[i - 1][j << 1];
                }
                lost[i][j] = max(lost[i][j], max(lost[i - 1][j << 1], lost[i - 1][j << 1 | 1])); 
            }
        }
    }
    cin >> w;
    if(lost[k][0] > w) {
        cout << "No Solution";
        return 0;
    }
    ans[win[k][0]] = w;
    for (int i = 0; i < 1 << k; i++) {
        if (i) cout << ' ';
        cout << ans[i] ;
    }
    return 0;
}