#include <iostream>
#include <map>
using namespace std;
int t;
string M, D, Y, final, symmetry;
map<string,string> A = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec","12"}};
int main(){
    for (cin >> t; t; t--) {
        cin >> M >> D >> Y;
        D.erase(D.end() - 1);
        M = A[M];
        if(D.size() == 1) D = "0" + D;
        while(Y.size() < 4) Y = "0" + Y;
        final = Y + M + D;
        symmetry = "Y";
        for (int i = 0; i < 4; i++) {
            if(final[i] != final[8 - i - 1]) {
                symmetry = "N";
                break;
            }
        }
        cout << symmetry << ' ' << final << '\n';
    }
    return 0;
}