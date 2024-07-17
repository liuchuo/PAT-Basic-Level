#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;
priority_queue<pair<int, string>> Q;
int N, C, t, room[500000], r, num, f;
map<string, int> Num;
vector<string> Uni(5005);
int main() {
    cin >> N >> C;
    for (int i = 1; i <= N; i++) {
        cin >> Uni[i] >> t;
        Q.push({t, Uni[i]});
    }
    while(Q.size()) {
        string SN = Q.top().second;
        num = Q.top().first;
        Q.pop();
        Num[SN]++;
        if (num >= C) {
            room[++r] = 0;
            if(num != C) Q.push({num - C, SN});
        } else {
            f = 0;
            for (int i = 1; i <= r; i++) {
                if (room[i] >= num) {
                    room[i] -= num;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                room[++r] = C - num;
            }
        }
    }
    for (int i = 1; i <= N; i++) cout << Uni[i] << ' ' << Num[Uni[i]] << '\n';
    cout << r;
    return 0;
}