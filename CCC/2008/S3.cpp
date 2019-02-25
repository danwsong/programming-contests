#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;
        
        vector<string> map(N);
        for (int i = 0; i < N; i++) {
            cin >> map[i];
        }
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        queue<pair<pair<int, int>, int>> bfs;
        bfs.push(make_pair(make_pair(0, 0), 1));
        
        int solution = -1;
        
        while (!bfs.empty()) {
            pair<pair<int, int>, int> next = bfs.front();
            bfs.pop();
            
            int x = next.first.first, y = next.first.second, dist = next.second;
            
            if (x < 0 || y < 0 || x >= N || y >= M)
                continue;
            
            if (visited[x][y])
                continue;
            visited[x][y] = true;
            
            if (map[x][y] == '*')
                continue;
            
            if (x == N - 1 && y == M - 1) {
                solution = dist;
                break;
            }
            
            if (map[x][y] == '+') {
                bfs.push(make_pair(make_pair(x + 1, y), dist + 1));
                bfs.push(make_pair(make_pair(x - 1, y), dist + 1));
                bfs.push(make_pair(make_pair(x, y + 1), dist + 1));
                bfs.push(make_pair(make_pair(x, y - 1), dist + 1));
            }
            if (map[x][y] == '|') {
                bfs.push(make_pair(make_pair(x + 1, y), dist + 1));
                bfs.push(make_pair(make_pair(x - 1, y), dist + 1));
            }
            if (map[x][y] == '-') {
                bfs.push(make_pair(make_pair(x, y + 1), dist + 1));
                bfs.push(make_pair(make_pair(x, y - 1), dist + 1));
            }
        }
    
        cout << solution << endl;
    }
    
    return 0;
}
