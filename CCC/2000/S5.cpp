#include <bits/stdc++.h>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int main() {
    int N;
    cin >> N;
    
    vector< pair<double, double> > points(N, make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    bool eaten[N];
    memset(eaten, false, sizeof(bool) * N);
    for (double wolfEntry = 0.00; wolfEntry <= 1000.00; wolfEntry += 0.05) {
        vector< pair< int, pair<double, double> > > sortedPoints;
        for (int i = 0; i < N; i++) {
            sortedPoints.push_back(make_pair(i, points[i]));
        }
        sort(sortedPoints.begin(), sortedPoints.end(), [wolfEntry](pair< int, pair<double, double> > a, pair< int, pair<double, double> > b) {
            return distance(a.second.first, a.second.second, wolfEntry, 0) < distance(b.second.first, b.second.second, wolfEntry, 0);
        });
        pair<double, double> closest = sortedPoints[0].second;
        eaten[sortedPoints[0].first] = true;
        int i = 1;
        while (i < N && distance(closest.first, closest.second, wolfEntry, 0) == distance(sortedPoints[i].second.first, sortedPoints[i].second.second, wolfEntry, 0)) {
            if (!eaten[sortedPoints[i].first])
                cout << wolfEntry << " " << sortedPoints[i].first << endl;
            eaten[sortedPoints[i++].first] = true;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (eaten[i]) {
            cout << fixed << setprecision(2) << "The sheep at (" << points[i].first << ", " << points[i].second << ") might be eaten.\n";
        }
    }
    
    return 0;
}
