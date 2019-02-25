#include <bits/stdc++.h>

using namespace std;

int main() {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--;
    sy--;
    ex--;
    ey--;
    
    queue<pair<pair<int, int>, int>> bfs;
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    bfs.push(make_pair(make_pair(sx, sy), 0));
    int moves = 0;
    while (!bfs.empty()) {
        pair<pair<int, int>, int> next = bfs.front();
        bfs.pop();
        
        if (next.first.first < 0 || next.first.first >= 8 || next.first.second < 0 || next.first.second >= 8)
            continue;
        
        if (visited[next.first.first][next.first.second])
            continue;
        visited[next.first.first][next.first.second] = true;
        
        if (next.first.first == ex && next.first.second == ey) {
            moves = next.second;
            break;
        }
        
        bfs.push(make_pair(make_pair(next.first.first + 1, next.first.second + 2), next.second + 1));
        bfs.push(make_pair(make_pair(next.first.first + 1, next.first.second - 2), next.second + 1));
        bfs.push(make_pair(make_pair(next.first.first - 1, next.first.second + 2), next.second + 1));
        bfs.push(make_pair(make_pair(next.first.first - 1, next.first.second - 2), next.second + 1));
        bfs.push(make_pair(make_pair(next.first.first + 2, next.first.second + 1), next.second + 1));
        bfs.push(make_pair(make_pair(next.first.first + 2, next.first.second - 1), next.second + 1));
        bfs.push(make_pair(make_pair(next.first.first - 2, next.first.second + 1), next.second + 1));
        bfs.push(make_pair(make_pair(next.first.first - 2, next.first.second - 1), next.second + 1));
    }
    cout << moves << endl;
    
    return 0;
}
