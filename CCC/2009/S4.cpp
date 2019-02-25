#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    int map[5000][5000];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = -1;
    for (int i = 0; i < T; i++) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        map[x - 1][y - 1] = c;
        map[y - 1][x - 1] = c;
    }
    int K;
    scanf("%d", &K);
    int pencils[5000];
    for (int i = 0; i < N; i++)
        pencils[i] = -1;
    for (int i = 0; i < K; i++) {
        int x, c;
        scanf("%d %d", &x, &c);
        pencils[x - 1] = c;
    }
    int src;
    scanf("%d", &src);
    
    int dist[5000];
    for (int i = 0; i < N; i++)
        dist[i] = 0x3FFFFFFF;
    
    int inQueue[5000];
    for (int i = 0; i < N; i++)
        inQueue[i] = 0;
    
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > dijkstra;
    
    dijkstra.push(make_pair(0, src - 1));
    inQueue[src - 1] = 1;
    dist[src - 1] = 0;
    
    while (!dijkstra.empty()) {
        int u = dijkstra.top().second;
        dijkstra.pop();
        
        inQueue[u] = 0;
        
        for (int v = 0; v < N; v++) {
            if (map[u][v] != -1 && dist[v] > dist[u] + map[u][v]) {
                dist[v] = dist[u] + map[u][v];
                if (!inQueue[v]) {
                    dijkstra.push(make_pair(dist[v], v));
                    inQueue[v] = 1;
                }
            }
        }
    }
    
    int minCost = 0x3FFFFFFF;
    for (int i = 0; i < N; i++) {
        if (pencils[i] != -1 && dist[i] != 0x3FFFFFFF) {
            minCost = min(minCost, pencils[i] + dist[i]);
        }
    }
    printf("%d\n", minCost);
    
    return 0;
}
