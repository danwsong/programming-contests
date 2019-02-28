#include <bits/stdc++.h>

using namespace std;

struct unionFind {
    vector<int> parent, rank;
    int count;
    
    unionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        count = n;
    }
    
    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    
    void unify(int p, int q) {
        if (connected(p, q))
            return;
        if (rank[find(p)] < rank[find(q)])
            parent[find(p)] = find(q);
        else if (rank[find(p)] > rank[find(q)])
            parent[find(q)] = find(p);
        else {
            parent[find(q)] = find(p);
            rank[find(p)]++;
        }
        count--;
    }
    
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};

struct edge {
    int src, dest, cost;
    bool active;
    
    edge(int src, int dest, int cost, bool active) {
        this->src = src;
        this->dest = dest;
        this->cost = cost;
        this->active = active;
    }
};

int main() {
    int N, M, D;
    cin >> N >> M >> D;
    
    vector<edge> edges;
    for (int i = 0; i < M; i++) {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        edges.push_back(edge(src - 1, dest - 1, cost, i < N - 1));
    }
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        if (a.cost == b.cost)
            return a.active > b.active;
        return a.cost < b.cost;
    });
    
    // Generate a minimum spanning tree of the graph, if any edges in the MST are not active, a day will need to be used to activate it
    unionFind components(N);
    int days = 0, maxCost = 0, index = 0;
    while (index < M && components.count > 1) {
        if (!components.connected(edges[index].src, edges[index].dest)) {
            components.unify(edges[index].src, edges[index].dest);
            maxCost = edges[index].cost;
            if (!edges[index].active)
                days++;
        }
        index++;
    }
    
    // Generate another MST
    components = unionFind(N);
    index = 0;
    while (index < M) {
        if (!components.connected(edges[index].src, edges[index].dest)) {
            // Add the edge if it costs less than the final edge
            if (edges[index].cost < maxCost || (edges[index].cost == maxCost && edges[index].active)) {
                components.unify(edges[index].src, edges[index].dest);
            } else if (edges[index].cost <= D && edges[index].active) {
                days--;
                break;
            }
        }
        index++;
    }
    
    cout << days << endl;
    
    return 0;
}