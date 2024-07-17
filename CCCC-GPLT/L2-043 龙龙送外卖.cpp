#include <iostream>
#include <queue>
using namespace std;
int N, M, Parent_num, new_address, passed_close_to_root, Round, Longest_path, Parent[100001], mark[100001], Distance[100001];
vector<int> Child[100001];
queue<pair<int, int> > Q;
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> Parent_num;
        if (Parent_num < 0) Parent[0] = i;
        else Child[Parent_num].push_back(i);
        Parent[i] = Parent_num;
    }
    mark[Parent[0]] = 1;
    Q.push({Parent[0], 0});
    while(!Q.empty()) {
        int id = Q.front().first, deep = Q.front().second;
        Q.pop();
        Distance[id] = deep;
        for (auto ite : Child[id]) Q.push({ite, deep + 1});
    }
    for (int i = 0; i < M; i++) {
        cin >> new_address;
        passed_close_to_root = new_address;
        while(!mark[passed_close_to_root]) {
            mark[passed_close_to_root] = 1;
            passed_close_to_root = Parent[passed_close_to_root];
        }
        Round += Distance[new_address] - Distance[passed_close_to_root];
        Longest_path = max(Longest_path, Distance[new_address]);
        cout << Round * 2 - Longest_path * 1 << '\n'; 
    } 
    return 0;
}