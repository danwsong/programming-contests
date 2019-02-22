#include <bits/stdc++.h>

using namespace std;

int main() {
    int graph[8][8];
    memset(graph, 0, sizeof(graph));

    graph[1][7] = 1;
    graph[1][4] = 1;
    graph[2][1] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;
    
    int x, y;
    cin >> x >> y;
    while (x || y) {
        graph[x][y] = 1;
        
        cin >> x >> y;
    }
    
    string solution = "";
    for (int i = 1; i <= 7; i++) {
        queue< pair< pair<int, int>, vector<int> > > bfs;
        queue<string> paths;
        bfs.push(make_pair(make_pair(i, 7), vector<int>(8, 0)));
        paths.push(to_string(i));
        while (!bfs.empty()) {
            pair< pair<int, int>, vector<int> > next = bfs.front();
            bfs.pop();
            
            int u = next.first.first, left = next.first.second;
            vector<int> visited = next.second;
            
            string path = paths.front();
            paths.pop();
            
            bool flag = false;
            for (int v = 1; v <= 7; v++) {
                if (u != v && visited[v] && graph[u][v]) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
            
            if (!visited[u]) {
                left--;
            }
            
            visited[u] = 1;
            
            if (!left) {
                solution = path;
                goto done;
            }
            
            for (int v = 1; v <= 7; v++) {
                if (!visited[v]) {
                    bfs.push(make_pair(make_pair(v, left), visited));
                    paths.push(path + " " + to_string(v));
                }
            }
        }
    }
    
done:  
    if (solution == "") {
        cout << "Cannot complete these tasks. Going to bed." << endl;
    } else {
        cout << solution << endl;
    }
    
    return 0;
}
