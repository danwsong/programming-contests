#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T) {
        int r, c, pr, pc, kr, kc;
        cin >> r >> c >> pr >> pc >> kr >> kc;
        
        queue< pair< pair< pair< pair<int, int>, pair<int, int> >, pair<int, int> >, int > > bfs;
        bfs.push(make_pair(make_pair(make_pair(make_pair(pr, pc), make_pair(pr, pc)), make_pair(kr, kc)), 0));
        vector< vector<bool> > visited(r + 1, vector<bool>(c + 1, false));
        int wonTurns = -1, stalemateTurns = -1;
        bool won = false, stalemate = false;
        while (!bfs.empty() && !won) {
            pair<int, int> ppos = bfs.front().first.first.first, kpos = bfs.front().first.second, lppos = bfs.front().first.first.second;
            int turn = bfs.front().second;
            bfs.pop();
            
            if (turn % 2 == 0) {
                if (ppos.first == r)
                    continue;
                
                bfs.push(make_pair(make_pair(make_pair(make_pair(ppos.first + 1, ppos.second), ppos), kpos), turn + 1));
            } else {
                if (kpos.first == lppos.first && kpos.second == lppos.second && !won) {
                    wonTurns = turn / 2;
                    won = true;
                }
                
                if (kpos.first == lppos.first + 1 && kpos.second == lppos.second && !stalemate) {
                    stalemateTurns = turn / 2;
                    stalemate = true;
                }
                
                if (visited[kpos.first][kpos.second])
                    continue;
                visited[kpos.first][kpos.second] = true;
                
                if (kpos.first + 1 <= r && kpos.second + 2 <= c && (!visited[kpos.first + 1][kpos.second + 2] || (kpos.first + 1 == ppos.first && kpos.second + 2 == ppos.second)))
                    bfs.push(make_pair(make_pair(make_pair(ppos, lppos), make_pair(kpos.first + 1, kpos.second + 2)), turn + 1));
                if (kpos.first + 1 <= r && kpos.second - 2 > 0 && (!visited[kpos.first + 1][kpos.second - 2] || (kpos.first + 1 == ppos.first && kpos.second - 2 == ppos.second)))
                    bfs.push(make_pair(make_pair(make_pair(ppos, lppos), make_pair(kpos.first + 1, kpos.second - 2)), turn + 1));
                if (kpos.first + 2 <= r && kpos.second + 1 <= c && (!visited[kpos.first + 2][kpos.second + 1] || (kpos.first + 2 == ppos.first && kpos.second + 1 == ppos.second)))
                    bfs.push(make_pair(make_pair(make_pair(ppos, lppos), make_pair(kpos.first + 2, kpos.second + 1)), turn + 1));
                if (kpos.first + 2 <= r && kpos.second - 1 > 0 && (!visited[kpos.first + 2][kpos.second - 1] || (kpos.first + 2 == ppos.first && kpos.second - 1 == ppos.second)))
                    bfs.push(make_pair(make_pair(make_pair(ppos, lppos), make_pair(kpos.first + 2, kpos.second - 1)), turn + 1));
                if (kpos.first - 1 > 0 && kpos.second + 2 <= c && (!visited[kpos.first - 1][kpos.second + 2] || (kpos.first - 1 == ppos.first && kpos.second + 2 == ppos.second)))
                    bfs.push(make_pair(make_pair(make_pair(ppos, lppos), make_pair(kpos.first - 1, kpos.second + 2)), turn + 1));
                if (kpos.first - 1 > 0 && kpos.second - 2 > 0 && (!visited[kpos.first - 1][kpos.second - 2] || (kpos.first - 1 == ppos.first && kpos.second - 2 == ppos.second)))
                    bfs.push(make_pair(make_pair(make_pair(ppos, lppos), make_pair(kpos.first - 1, kpos.second - 2)), turn + 1));
                if (kpos.first - 2 > 0 && kpos.second + 1 <= c && (!visited[kpos.first - 2][kpos.second + 1] || (kpos.first - 2 == ppos.first && kpos.second + 1 == ppos.second)))
                    bfs.push(make_pair(make_pair(make_pair(ppos, lppos), make_pair(kpos.first - 2, kpos.second + 1)), turn + 1));
                if (kpos.first - 2 > 0 && kpos.second - 1 > 0 && (!visited[kpos.first - 2][kpos.second - 1] || (kpos.first - 2 == ppos.first && kpos.second - 1 == ppos.second)))
                    bfs.push(make_pair(make_pair(make_pair(ppos, lppos), make_pair(kpos.first - 2, kpos.second - 1)), turn + 1));
            }
        }
        
        if (won) {
            cout << "Win in " << wonTurns << " knight move(s).\n";
        } else if (stalemate) {
            cout << "Stalemate in " << stalemateTurns << " knight move(s).\n";
        } else {
            cout << "Loss in " << (r - pr - 1) << " knight move(s).\n";
        }
        
        T--;
    }
    
    return 0;
}
