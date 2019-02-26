#include <bits/stdc++.h>

using namespace std;

struct edge {
    int destination, time, hullWear;
    
    edge(int d, int t, int w) {
        destination = d;
        time = t;
        hullWear = w;
    }
};

int main() {
    int hullThickness, numberOfIslands, numberOfRoutes, source, destination;
    
    cin >> hullThickness >> numberOfIslands >> numberOfRoutes;
    vector< vector<edge> > vertices(numberOfIslands + 1);
    for (int i = 0; i < numberOfRoutes; i++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        vertices[a].push_back(edge(b, t, h));
        vertices[b].push_back(edge(a, t, h));
    }
    cin >> source >> destination;
    
    vector< vector<int> > distanceWithHullBurn(numberOfIslands + 1, vector<int>(hullThickness + 1, 0x3FFFFFFF));
    vector<bool> verticesInQueue(numberOfIslands + 1, false);
    
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > vertexQueue;
    vertexQueue.push(make_pair(0, source));
    
    distanceWithHullBurn[source][0] = 0;
    verticesInQueue[source] = true;
    
    while (!vertexQueue.empty()) {
        int currentVertex = vertexQueue.top().second;
        verticesInQueue[currentVertex] = false;
        vertexQueue.pop();
        
        for (edge currentEdge : vertices[currentVertex]) {
            for (int hullBurn = 0; hullBurn < hullThickness - currentEdge.hullWear; hullBurn++) {
                if (distanceWithHullBurn[currentVertex][hullBurn] + currentEdge.time < distanceWithHullBurn[currentEdge.destination][currentEdge.hullWear + hullBurn]) {
                    distanceWithHullBurn[currentEdge.destination][currentEdge.hullWear + hullBurn] = distanceWithHullBurn[currentVertex][hullBurn] + currentEdge.time;
                    if (!verticesInQueue[currentEdge.destination]) {
                        verticesInQueue[currentEdge.destination] = true;
                        vertexQueue.push(make_pair(distanceWithHullBurn[currentVertex][hullBurn] + currentEdge.time, currentEdge.destination));
                    }
                }
            }
        }
    }
    
    int fastestRoute = 0x3FFFFFFF;
    for (int hullBurn = 0; hullBurn < hullThickness; hullBurn++) {
        fastestRoute = min(fastestRoute, distanceWithHullBurn[destination][hullBurn]);
    }
    
    if (fastestRoute == 0x3FFFFFFF) {
        cout << -1 << endl;
    } else {
        cout << fastestRoute << endl;
    }
    
    return 0;
}
