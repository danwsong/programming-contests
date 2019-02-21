#include <bits/stdc++.h>

using namespace std;

int main() {
    int cities, roads, destinations;
    scanf("%d%d%d", &cities, &roads, &destinations);
    
    vector< vector< pair<int, int> > > graph(cities + 1);
    for (int i = 0; i < roads; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }
    
    priority_queue< pair<int, int> > trucks;
    vector<int> weights(cities + 1, -1);
    trucks.push(make_pair(0x3FFFFFFF, 1));
    while (!trucks.empty()) {
        int load = trucks.top().first, u = trucks.top().second;
        trucks.pop();
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first, w = graph[u][i].second;
            if (min(load, w) > weights[v]) {
                weights[v] = min(load, w);
                trucks.push(make_pair(weights[v], v));
            }
        }
    }
    
    int minWeight = 0x3FFFFFFF;
    for (int i = 0; i < destinations; i++) {
        int c;
        scanf("%d", &c);
        if (weights[c] != -1) {
            minWeight = min(minWeight, weights[c]);
        }
    }
    printf("%d\n", minWeight);
    
    return 0;
}
