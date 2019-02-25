#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    
    queue<int> bfs;
    
    vector<bool> visited1(N, false);
    bfs.push(a);
    while (!bfs.empty()) {
        int next = bfs.front();
        bfs.pop();
        if (visited1[next])
            continue;
        visited1[next] = true;
        for (int i = 0; i < graph[next].size(); i++)
            bfs.push(graph[next][i]);
    }
    
    vector<bool> visited2(N, false);
    bfs.push(b);
    while (!bfs.empty()) {
        int next = bfs.front();
        bfs.pop();
        if (visited2[next])
            continue;
        visited2[next] = true;
        for (int i = 0; i < graph[next].size(); i++)
            bfs.push(graph[next][i]);
    }
    
    if (visited1[b])
        cout << "yes" << endl;
    if (visited2[a])
        cout << "no" << endl;
    if (!visited1[b] && !visited2[a])
        cout << "unknown" << endl;
    
    return 0;
}
