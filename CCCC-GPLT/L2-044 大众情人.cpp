#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int N, Dis[501][501];
char c;
vector<int> Nan, Nv;
map<int, set<int> > M_Ans, F_Ans;
void findlover(vector<int> &Find, vector<int> &Base, map<int, set<int> > &Target, int mark = 0) {
    for (int i = 0, score = 0; i < (int)Find.size(); i++, score = 0) {
        for (int j = 0; j < (int)Base.size(); j++) score = max(score, Dis[Base[j]][Find[i]]);
        Target[score].insert(Find[i]);
    }
    for (auto ite : Target.begin()->second) {
        if (mark++) cout << ' ';
        cout << ite;
    }
}
int main() {
    cin >> N;
    fill (Dis[0], Dis[0] + 501 * 501, 1e9);
    for (int i = 1, K, fri, dis; i <= N; i++) {
        cin >> c >> K;
        if (c == 'F') Nv.push_back(i);
        else Nan.push_back(i);
        for (int j = 0; j < K; ++j) {
            cin >> fri >> c >> dis;
            Dis[i][fri] = dis;
        }
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
    findlover(Nv, Nan, F_Ans);
    cout << '\n';
    findlover(Nan, Nv, M_Ans);
    return 0;
}