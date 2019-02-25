#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, M, t;
    cin >> h >> M;
    bool flag = false;
    for (t = 1; t <= M; t++) {
        if (-6 * t * t * t * t + h * t * t * t + 2 * t * t + t <= 0) {
            flag = true;
            break;
        }
    }
    
    if (flag)
        cout << "The balloon first touches ground at hour:" << endl << t << endl;
    else
        cout << "The balloon does not touch ground in the given time." << endl;
    
    return 0;
}
