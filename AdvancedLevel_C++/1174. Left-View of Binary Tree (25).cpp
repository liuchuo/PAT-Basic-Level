#include <iostream>
using namespace std;
int N, pre[30], in[30], t[30];
void deal(int ins, int ine, int prerootindex, int level) {
    if (ins > ine) return;
    if (t[level] == 0) {
        t[level] = pre[prerootindex];
    }
    int pos = ins;
    while(in[pos] != pre[prerootindex]) ++pos;
    deal(ins, pos - 1, prerootindex + 1, level + 1);
    deal(pos + 1, ine, prerootindex + 1 + pos - ins, level + 1);
}
int main(){
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> in[i];
    for (int i = 1; i <= N; i++) cin >> pre[i];
    deal(1, N, 1, 1);
    for (int i = 1; t[i]; i++) {
        if (i != 1) cout << ' ';
        cout << t[i];
    }
    return 0;
}