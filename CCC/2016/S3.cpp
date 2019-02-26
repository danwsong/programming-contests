#include <bits/stdc++.h>

using namespace std;

vector<bool> isPhoRestaurant, subtreeContainsPho;
vector<int> phoRestaurants;
vector< vector<int> > graph;

void depthFirstSearch(int cur, int prev, int dist, int &maxDistNode, int &maxDist) {
    dist++;
    for (int next : graph[cur]) {
        if (next != prev) {
            if (isPhoRestaurant[next] && dist > maxDist) {
                maxDist = dist;
                maxDistNode = next;
            }
            depthFirstSearch(next, cur, dist, maxDistNode, maxDist);
        }
    }
}

void solveSubtreeContainPho(int cur, int prev) {
    if (isPhoRestaurant[cur])
        subtreeContainsPho[cur] = true;
    for (int next : graph[cur]) {
        if (next != prev) {
            solveSubtreeContainPho(next, cur);
            if (subtreeContainsPho[next])
                subtreeContainsPho[cur] = true;
        }
    }
}

void subtreeCost(int cur, int prev, int &cost) {
    for (int next : graph[cur]) {
        if (next != prev) {
            if (subtreeContainsPho[next]) {
                cost += 2;
                subtreeCost(next, cur, cost);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    isPhoRestaurant = vector<bool>(N, false);
    phoRestaurants = vector<int>(M);
    graph = vector< vector<int> >(N);

    for (int i = 0; i < M; i++) {
        cin >> phoRestaurants[i];
        isPhoRestaurant[phoRestaurants[i]] = true;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int maxDist = 0, start = 0, end = 0;
    depthFirstSearch(phoRestaurants[0], phoRestaurants[0], 0, start, maxDist);
    depthFirstSearch(start, start, 0, end, maxDist);
    subtreeContainsPho = vector<bool>(N, false);
    solveSubtreeContainPho(start, start);
    int cost = 0;
    subtreeCost(start, start, cost);
    cout << cost - maxDist << endl;
	
    return 0;
}