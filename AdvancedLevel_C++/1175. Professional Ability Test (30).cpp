#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int v, score, voucher;
    bool operator < (const node &x) const {
        if(score != x.score) return score > x.score;
        else return voucher < x.voucher;
    }
};
struct bian {
    int next, S, D;
};
vector<bian> E[1005];
vector<pair<int,int>> Dis(1005, {2e9, -1});
int N, M, T1, T2, S, D, f, T, in[1005], in2[1005], Last[1005];
queue<int> DAG;
int huan() {
    vector<int> S;
    while(DAG.size()) {
        int now = DAG.front();
        DAG.pop();
        S.push_back(now);
        for(auto it : E[now]) {
            in2[it.next]--;
            if(!in2[it.next]) DAG.push(it.next);
        }
    }
    return S.size() == N;
}
void dijkstra() {
    vector<int> vis(1005);
    priority_queue<node> Q;
    Q.push({1002, 0, 0});
    Dis[1002].first = Dis[1002].second = 0;
    while(Q.size()) {
        node now = Q.top();
        Q.pop();
        if(vis[now.v]) continue;
        vis[now.v] = 1;
        Dis[now.v].first = now.score;
        Dis[now.v].second = now.voucher;
        for (auto it : E[now.v]) {
            if(vis[it.next]) continue;
            if((Dis[it.next].first > Dis[now.v].first + it.S) || ((Dis[it.next].first == Dis[now.v].first + it.S) && (Dis[it.next].second < Dis[now.v].second + it.D))) {
                Dis[it.next].first = Dis[now.v].first + it.S;
                Dis[it.next].second = Dis[now.v].second + it.D;
                Last[it.next] = now.v;
                Q.push({it.next, Dis[it.next].first, Dis[it.next].second});
            }
        }
    }
    return;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> T1 >> T2 >> S >> D;
        E[T1].push_back({T2, S, D});
        in[T2]++, in2[T2]++;
    }
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) {
            E[1002].push_back({i, 0, 0});
            DAG.push(i);
        }
    }
    f = huan();
    dijkstra();
    cin >> T;
    if(f) cout << "Okay.\n";
    else cout << "Impossible.\n";
    for (int i = 1, q; i <= T; i++) {
        cin >> q;
        if(!in[q]) cout << "You may take test " << q << " directly.\n";
        else if(!f) cout << "Error.\n";
        else {
            vector<int> path;
            int now = q;
            while(q != 1002) {
                path.push_back(q);
                q = Last[q];
            }
            for (int j = path.size() - 1; j >= 0; j--) {
                cout << path[j];
                if(j) cout << "->";
            }
            cout << '\n';
        }
    }
    return 0;
}