#include <bits/stdc++.h>

using namespace std;

int main() {
    int moves[5][4] = {
        { 2, 1, 0, 2 },
        { 1, 1, 1, 1 },
        { 0, 0, 2, 1 },
        { 0, 3, 0, 0 },
        { 1, 0, 0, 1 },
    };
    
    bool win[31][31][31][31];
    for (int a = 0; a <= 30; a++)
        for (int b = 0; b <= 30; b++)
            for (int c = 0; c <= 30; c++)
                for (int d = 0; d <= 30; d++)
                    win[a][b][c][d] = false;
    
    for (int a = 0; a <= 30; a++)
        for (int b = 0; b <= 30; b++)
            for (int c = 0; c <= 30; c++)
                for (int d = 0; d <= 30; d++)
                    for (int m = 0; m < 5; m++)
                        if (a - moves[m][0] >= 0 && b - moves[m][1] >= 0 && c - moves[m][2] >= 0 && d - moves[m][3] >= 0 && !win[a - moves[m][0]][b - moves[m][1]][c - moves[m][2]][d - moves[m][3]])
                            win[a][b][c][d] = true;
    
    int T;
    cin >> T;
    while (T--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        
        cout << (win[A][B][C][D] ? "Patrick" : "Roland") << endl;
    }
    
    return 0;
}
