#include <iostream>
using namespace std;
int prohibit, accompany, q1, q2;
int main() {
    cin >> prohibit >> accompany >> q1 >> q2;
    cout << q1 << '-';
    if (q1 >= prohibit && q2 >= prohibit) cout << "Y " << q2 << "-Y\nhuan ying ru guan";
    else if (q1 < prohibit && q2 < prohibit) cout << "N " << q2 << "-N\nzhang da zai lai ba";
    else if (q1 >= accompany) cout << "Y " << q2 << "-Y\nqing 1 zhao gu hao 2";
    else if (q2 >= accompany) cout << "Y " << q2 << "-Y\nqing 2 zhao gu hao 1";
    else if (q1 >= prohibit) cout << "Y " << q2 << "-N\n1: huan ying ru guan";
    else cout << "N " << q2 << "-Y\n2: huan ying ru guan";
    return 0;
}