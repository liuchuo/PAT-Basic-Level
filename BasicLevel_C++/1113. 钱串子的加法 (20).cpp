#include <iostream>
using namespace std;
string a, b, ans;
int num_a, num_b, now, jin, index;
int main(){
    cin >> a >> b;
    if(a.size() > b.size()) swap(a, b);
    string c(b.size() - a.size(), '0');
    a = c + a;
    ans.resize(a.size());
    for (int i = b.size() - 1; i >= 0; i--) {
        if (a[i] >= '0' && a[i] <= '9') num_a = a[i] - '0';
        else num_a = a[i] - 'a' + 10;
        if (b[i] >= '0' && b[i] <= '9') num_b = b[i] - '0';
        else num_b = b[i] - 'a' + 10;
        now = (num_a + num_b + jin) % 30;
        jin = (num_a + num_b + jin) / 30;
        if(now < 10) ans[i] = (char)(now + '0');
        else ans[i] = (char)(now - 10 + 'a');
    }
    if (jin) ans = "1" + ans;
    while(index < ans.size() - 1 && ans[index] == '0') ++index;
    while(index < ans.size()) cout << ans[index++];
    return 0;
}