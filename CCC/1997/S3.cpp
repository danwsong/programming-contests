#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T) {
        int u, o = 0, e = 0;
        cin >> u;
        printf("Round 0: %d undefeated, %d one-loss, %d eliminated\n", u, o, e);
        int r = 0;
        while (u + o > 1) {
            if (u == 1 && o == 1) {
                u--;
                o++;
            } else {
                e += o / 2;
                o -= o / 2;
                o += u / 2;
                u -= u / 2;
            }
            r++;
            printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", r, u, o, e);
        }
        printf("There are %d rounds.", r);
        
        T--;
        printf("\n");
    }
    return 0;
}
