#include <iostream>
using namespace std;
int Hat[105], Guess, Right, Wrong, N, K;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> Hat[i];
    cin >> K;
    while(K--) {
        Right = Wrong = 0;
        for (int i = 1; i <= N; i++) {
            cin >> Guess;
            if (Guess && Guess == Hat[i]) Right = 1;
            else if (Guess && Guess != Hat[i]) Wrong = 1;
        }
        if (Wrong || !Right) cout << "Ai Ya\n";
        else cout << "Da Jiang!!!\n";
    }
    return 0;
}