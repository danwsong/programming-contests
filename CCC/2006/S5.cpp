#include <bits/stdc++.h>

using namespace std;

int main() {
    int rows, cols, lonely, full, birth;
    cin >> rows >> cols >> lonely >> full >> birth;
    
    int original = 0;
    for (int r = 1; r <= rows; r++) {
        string row;
        cin >> row;
        for (int c = 1; c <= cols; c++) {
            original <<= 1;
            original |= (row[c - 1] == '*') ? 1 : 0;
        }
    }
    
    vector< vector<int> > graph(pow(2, rows * cols), vector<int>());
    for (int i = 0; i < graph.size(); i++) {
        // convert from number to 2D grid
        int temp = i;
        vector< vector<int> > first(rows + 2, vector<int>(cols + 2, 0));
        for (int r = rows; r >= 1; r--) {
            for (int c = cols; c >= 1; c--) {
                first[r][c] = temp & 1;
                temp >>= 1;
            }
        }
        
        // simulate one generation
        vector< vector<int> > second(rows + 2, vector<int>(cols + 2, 0));
        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                int sum = -first[r][c];
                for (int x = r - 1; x <= r + 1; x++)
                    for (int y = c - 1; y <= c + 1; y++)
                        sum += first[x][y];
                if (first[r][c] == 1) {
                    second[r][c] = (sum < lonely || sum > full) ? 0 : 1;
                } else {
                    second[r][c] = (sum > birth) ? 1 : 0;
                }
            }
        }
        
        // convert from 2D grid to number
        int j = 0;
        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                j <<= 1;
                j |= second[r][c];
            }
        }
        
        // add connection to graph
        graph[j].push_back(i);
    }
    
    queue< pair<int, int> > bfs;
    vector<bool> visited(graph.size(), false);
    bfs.push(make_pair(original, 0));
    int minDist = 0x7FFFFFFF;
    while (!bfs.empty()) {
        int cur = bfs.front().first, dist = bfs.front().second;
        bfs.pop();
        
        visited[cur] = true;
        
        if (graph[cur].size() == 0) {
            minDist = dist;
            break;
        }
        
        for (int next : graph[cur]) {
            if (!visited[next])
                bfs.push(make_pair(next, dist + 1));
        }
    }
    cout << (minDist == 0x7FFFFFFF ? -1 : minDist) << endl;
    
    return 0;
}
