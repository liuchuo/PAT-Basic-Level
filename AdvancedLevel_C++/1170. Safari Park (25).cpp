#include <iostream>
#include <map>
#include <vector>
using namespace std;
int N, R, K, M, flag, E[505][505];
int main() {
    cin >> N >> R >> K;
    for (int i = 1, u, v; i <= R; i++) {
        cin >> u >> v;
        E[u][v] = E[v][u] = 1;
    }
    for (cin >> M; M; M--) {
        map<int, vector<int>> A;
        for (int i = 1, a; i <= N; i++) {
            cin >> a;
            A[a].push_back(i);
        }
        if(A.size() > K) cout << "Error: Too many species.\n";
        else if (A.size() < K) cout << "Error: Too few species.\n";
        else {
            flag = 1;
            for (auto it : A) {
                for (int i = 0; i < it.second.size(); i++) {
                    for (int j = i + 1; j < it.second.size(); j++) {
                        if(E[it.second[i]][it.second[j]]) {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            if (flag) cout << "Yes\n";
            else cout << "No\n";
        }
        
    }
    return 0;
}