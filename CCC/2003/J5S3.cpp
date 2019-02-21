#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, r, c;
    cin >> f >> r >> c;
    
    vector<string> map(r);
    for (int i = 0; i < r; i++) {
        cin >> map[i];
    }
    
    vector<int> room(r * c, -1);
    stack<pair<pair<int, int>, int>> dfs;
    vector<vector<int>> visited(r, vector<int>(c, false));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (map[i][j] == '.') {
                room[i * c + j] = i * c + j;
                dfs.push(make_pair(make_pair(i, j), i * c + j));
            }
    
    while (!dfs.empty()) {
        pair<pair<int, int>, int> next = dfs.top();
        dfs.pop();
        
        if (next.first.first < 0 || next.first.first >= r || next.first.second < 0 || next.first.second >= c)
            continue;
        if (map[next.first.first][next.first.second] == 'I')
            continue;
        if (visited[next.first.first][next.first.second])
            continue;
        visited[next.first.first][next.first.second] = true;
        
        room[next.first.first * c + next.first.second] = next.second;
        
        dfs.push(make_pair(make_pair(next.first.first + 1, next.first.second), next.second));
        dfs.push(make_pair(make_pair(next.first.first - 1, next.first.second), next.second));
        dfs.push(make_pair(make_pair(next.first.first, next.first.second + 1), next.second));
        dfs.push(make_pair(make_pair(next.first.first, next.first.second - 1), next.second));
    }
    
    vector<int> freq(r * c, 0);
    for (int i = 0; i < r * c; i++)
        if (room[i] != -1)
            freq[room[i]]++;
            
    sort(freq.rbegin(), freq.rend());
    
    int rooms = 0;
    for (int i = 0; i < r * c && freq[i] <= f; i++) {
        if (freq[i] > 0) {
            rooms++;
            f -= freq[i];
        }
    }  
    
    cout << rooms << " room" << (rooms == 1 ? "" : "s") << ", " << f << " square metre(s) left over" << endl;
    
    return 0;
}
