#include <bits/stdc++.h>

using namespace std;

struct info {
    int pen, cost;
    
    info(int pen, int cost) {
        this->pen = pen;
        this->cost = cost;
    }
};

struct edge {
    int src, dst, cost;
    
    edge(int src, int dst, int cost) {
        this->src = src;
        this->dst = dst;
        this->cost = cost;
    }
};

struct unionFind {
    vector<int> parent, rank;
    long count;
    
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
        if (rank[find(p)] < rank[find(q)]) {
            parent[find(p)] = find(q);
        } else if (rank[find(p)] > rank[find(q)]) {
            parent[find(q)] = find(p);
        } else {
            parent[find(q)] = find(p);
            rank[find(p)]++;
        }
        count--;
    }
    
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};

int spanningTreeCost(int N, vector<edge> edges) {
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.cost < b.cost;
    });
    unionFind mst(N);
    int cost = 0, index = 0;
    while (mst.count > 1 && index < edges.size()) {
        if (!mst.connected(edges[index].src, edges[index].dst)) {
            mst.unify(edges[index].src, edges[index].dst);
            cost += edges[index].cost;
        }
        index++;
    }
    if (index == edges.size() && mst.count > 1)
        return 0x7FFFFFFF;
    return cost;
}

int main() {
    int N;
    cin >> N;
    
    vector< vector<int> > graph(N + 1, vector<int>(N + 1, 0x7FFFFFFF));
    for (int i = 0; i <= N; i++)
        graph[i][i] = 0;
    
    vector< vector<info> > edges(1001, vector<info>(1001, info(-1, 0)));
    for (int pen = 0; pen < N; pen++) {
        int numEdges;
        cin >> numEdges;
        
        vector<int> vertices(numEdges), costs(numEdges);
        for (int e = 0; e < numEdges; e++)
            cin >> vertices[e];
        for (int e = 0; e < numEdges; e++)
            cin >> costs[e];
        
        for (int u = 0; u < numEdges; u++) {
            int v = (u + 1) % numEdges;
            
            if (edges[vertices[u]][vertices[v]].cost > 0) {
                if (graph[pen][edges[vertices[u]][vertices[v]].pen] > costs[u]) {
                    graph[pen][edges[vertices[u]][vertices[v]].pen] = costs[u];
                    graph[edges[vertices[u]][vertices[v]].pen][pen] = costs[u];
                }
                edges[vertices[u]][vertices[v]].pen = -1;
                edges[vertices[v]][vertices[u]].pen = -1;
            } else {
                edges[vertices[u]][vertices[v]].cost = costs[u];
                edges[vertices[u]][vertices[v]].pen = pen;
                edges[vertices[v]][vertices[u]].cost = costs[u];
                edges[vertices[v]][vertices[u]].pen = pen;
            }
        }
    }
    
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (edges[i][j].pen >= 0 && graph[edges[i][j].pen][N] > edges[i][j].cost) {
                graph[edges[i][j].pen][N] = edges[i][j].cost;
                graph[N][edges[i][j].pen] = edges[i][j].cost;
            }
        }
    }
    
    vector<edge> edgeList, outsideEdgeList;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (graph[i][j] != 0x7FFFFFFF) {
                edgeList.push_back(edge(i, j, graph[i][j]));
                outsideEdgeList.push_back(edge(i, j, graph[i][j]));
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (graph[i][N] != 0x7FFFFFFF) {
            outsideEdgeList.push_back(edge(i, N, graph[i][N]));
        }
    }
    int minCost = min(spanningTreeCost(N, edgeList), spanningTreeCost(N + 1, outsideEdgeList));
    cout << minCost << endl;
    
    return 0;
}
