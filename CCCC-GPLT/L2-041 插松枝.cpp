#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int N, M, K, tui;
stack<int> he;
vector<int> temp;
void outprint() {
    for (int i = 0; i < temp.size(); i++) {
        if (i) cout << ' ';
            cout << temp[i];
        }
    cout << '\n';
    temp.clear();
}
int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> tui;
        tuihaimeiyong:
        while (!he.empty()) {
            if (temp.empty() || he.top() <= temp.back()) {
                temp.push_back(he.top());
                he.pop();
            }
            else break;
            if (temp.size() == K) outprint();
        }
        if (temp.empty() || tui <= temp.back()) temp.push_back(tui);
        else if(he.size() < M) he.push(tui);
        else {
            outprint();
            goto tuihaimeiyong;
        }
        if (temp.size() == K) outprint();
    }
    while(!he.empty()) {
        if (temp.empty() || he.top() <= temp.back()) {
            temp.push_back(he.top());
            he.pop();
        }
        else outprint();
        if (temp.size() == K) outprint();
    }
    for (int j = 0; j < temp.size(); j++) {
        if (j) cout << ' ';
        cout << temp[j];
    }
    return 0;
}