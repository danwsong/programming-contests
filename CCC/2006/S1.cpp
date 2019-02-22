#include <bits/stdc++.h>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    
    string possible[5] = { "", "", "", "", "" };
    
    for (int i = 0; i < A.size() / 2; i++) {
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                if (A[i * 2 + a] == 'A' + i || B[i * 2 + b] == 'A' + i) {
                    possible[i] += (char) ('A' + i);
                } else {
                    possible[i] += (char) ('a' + i);
                }
            }
        }
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        bool flag = false;
        for (int c = 0; c < 5; c++) {
            if (possible[c].find(s[c]) == -1) {
                cout << "Not their baby!\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "Possible baby.\n";
    }
    
    return 0;
}
