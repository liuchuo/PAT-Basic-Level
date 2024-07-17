#include <iostream>
#include <queue>
using namespace std;
int N, M, A[100005], index, now;
priority_queue<int, vector<int>, greater<int>> Q1, Q2;
int main(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (i <= M) Q1.push(A[i]);
    }
    index = M + 1;
    while (Q1.size()) {
        now = Q1.top();
        cout << now;
        Q1.pop();
        if(index <= N) {
            if (A[index] < now) Q2.push(A[index]);
            else Q1.push(A[index]);
            ++index;
        }
        if (Q1.size()) cout << ' ';
        else {
            swap(Q1, Q2);
            cout << '\n';
        }
    }
    return 0;
}