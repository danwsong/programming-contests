#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    
    vector<string> map(r);
    for (int i = 0; i < r; i++) {
        cin >> map[i];
    }
    
    int m;
    cin >> m;
    string moves = "";
    for (int i = 0; i < m; i++) {
        string next;
        cin >> next;
        moves += next;
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int d = 0; d < 4; d++) {
                int tempI = i, tempJ = j, dir = d, step = 0;
                
                while (tempI >= 0 && tempI < r && tempJ >= 0 && tempJ < c && (map[tempI][tempJ] == '.' || map[tempI][tempJ] == '*') && step < moves.size()) {
                    if (moves[step] == 'R') {
                        dir = (dir + 3) % 4;
                    } else if (moves[step] == 'L') {
                        dir = (dir + 1) % 4;
                    } else if (moves[step] == 'F') {
                        if (dir == 0)
                            tempJ++;
                        if (dir == 1)
                            tempI--;
                        if (dir == 2)
                            tempJ--;
                        if (dir == 3)
                            tempI++;
                    }
                    step++;
                }
                
                if (step >= moves.size() && tempI >= 0 && tempI < r && tempJ >= 0 && tempJ < c && map[tempI][tempJ] == '.')
                    map[tempI][tempJ] = '*';
            }
        }
    }
    
    for (int i = 0; i < r; i++) {
        cout << map[i] << "\n";
    }
    
    return 0;
}
