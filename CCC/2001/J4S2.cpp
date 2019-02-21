#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int start, stop;
        cin >> start >> stop;
        
        int spiral[10][10];
        memset(spiral, 0, sizeof(spiral));
        
        int r = 4, c = 4;
        
        int sideLen = 0;
        for (int i = start; i <= stop; ) {
            sideLen++;
            
            for (int j = 0; i <= stop && j < sideLen; i++, j++, r++) {
                spiral[r][c] = i;
            }
            
            for (int j = 0; i <= stop && j < sideLen; i++, j++, c++) {
                spiral[r][c] = i;
            }
            
            sideLen++;
            
            for (int j = 0; i <= stop && j < sideLen; i++, j++, r--) {
                spiral[r][c] = i;
            }
            
            for (int j = 0; i <= stop && j < sideLen; i++, j++, c--) {
                spiral[r][c] = i;
            }
        }
        
        int firstR = -1, firstC = -1;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (spiral[i][j] != 0 && firstR == -1)
                    firstR = i;
                if (spiral[j][i] != 0 && firstC == -1)
                    firstC = i;
            }
        }
        int lastR = -1, lastC = -1;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (spiral[i][j] != 0)
                    lastR = i;
                if (spiral[j][i] != 0)
                    lastC = i;
            }
        }

        int maxWidth[10] = { 0 };
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (spiral[i][j] < 10)
                    maxWidth[j] = max(maxWidth[j], 1);
                else
                    maxWidth[j] = max(maxWidth[j], 2);
            }
        }

        for (int i = firstR; i <= lastR; i++) {
            for (int j = firstC; j <= lastC; j++) {
                if (spiral[i][j] == 0) {
                    if (maxWidth[j] == 1)
                        cout << " ";
                    else
                        cout << "  ";
                } else if (spiral[i][j] < 10) {
                    if (maxWidth[j] == 1)
                        cout << "" << spiral[i][j];
                    else
                        cout << " " << spiral[i][j];
                } else {
                    cout << spiral[i][j];
                }
                if (j < lastC)
                    cout << " ";
            }
            cout << "\n";
        }
        
        if (t < T)
            cout << "\n";
    }
    
    return 0;
}
