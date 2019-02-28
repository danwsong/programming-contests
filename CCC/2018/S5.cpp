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

struct edge {
    int src, dst, cost;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numPlanets, numCities, numFlights, numPortals;
    cin >> numPlanets >> numCities >> numFlights >> numPortals;
    
    edge flights[numFlights], portals[numPortals];
    long originalCost = 0;
    for (int i = 0; i < numFlights; i++) {
        cin >> flights[i].src >> flights[i].dst >> flights[i].cost;
        if (flights[i].src > flights[i].dst)
            swap(flights[i].src, flights[i].dst);
        originalCost += (long) flights[i].cost * (long) numPlanets;
    }
    for (int i = 0; i < numPortals; i++) {
        cin >> portals[i].src >> portals[i].dst >> portals[i].cost;
        if (portals[i].src > portals[i].dst)
            swap(portals[i].src, portals[i].dst);
        originalCost += (long) portals[i].cost * (long) numCities;
    }
    
    sort(flights, flights + numFlights, [](edge a, edge b) {
        return a.cost < b.cost;
    });
    sort(portals, portals + numPortals, [](edge a, edge b) {
        return a.cost < b.cost;
    });
    
    unionFind cities(numCities + 1), planets(numPlanets + 1);
    
    long minimumCost = 0;
    int flight = 0, portal = 0;
    while (cities.count > 2 || planets.count > 2) {
        if (portal >= numPortals || (flight < numFlights && flights[flight].cost <= portals[portal].cost)) {
            if (!cities.connected(flights[flight].src, flights[flight].dst)) {
                minimumCost += (long) flights[flight].cost * (long) (planets.count - 1);
                cities.unify(flights[flight].src, flights[flight].dst);
            }
            flight++;
        } else {
            if (!planets.connected(portals[portal].src, portals[portal].dst)) {
                minimumCost += (long) portals[portal].cost * (long) (cities.count - 1);
                planets.unify(portals[portal].src, portals[portal].dst);
            }
            portal++;
        }
    }
    
    cout << (originalCost - minimumCost) << endl;
    
    return 0;
}