#include <iostream>
#include <queue>
using namespace std;
int N, M, island, precious, p, NX[4] = {1, -1, 0, 0}, NY[4] = {0, 0, 1, -1};
string A[100005];
queue<pair<int,int>> Q;
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (A[i][j] != '0') {
                ++island;
                Q.push({i, j});
                p = 0;
                if(A[i][j] >= '2') p = 1;
                A[i][j] = '0';
                while(Q.size()) {
                    int nowx = Q.front().first, nowy = Q.front().second;
                    Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int X = nowx + NX[k], Y = nowy + NY[k];
                        if(X >= 0 && X < N && Y >= 0 && Y < M && A[X][Y] >= '1') {
                            if(A[X][Y] >= '2') p = 1;
                            Q.push({X, Y});
                            A[X][Y] = '0';
                        }
                    }
                }
                if(p) ++precious;
            }
        }
    cout << island << ' ' << precious;
    return 0;
}