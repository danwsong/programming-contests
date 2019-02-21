#include <bits/stdc++.h>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int N;
    cin >> N;
    
    vector< pair<int, int> > points(N, make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    double smallestTwo = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double centerX = (double) (points[i].first + points[j].first) / 2;
            double centerY = (double) (points[i].second + points[j].second) / 2;
            double radius = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2)) / 2;
            bool allWithin = true;
            for (int p = 0; p < N; p++)
                if (dist((double) points[p].first, (double) points[p].second, centerX, centerY) > radius)
                    allWithin = false;
            if (allWithin)
                smallestTwo = max(smallestTwo, radius * 2);
        }
    }
    
    double smallestThree = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                pair<int, int> A = points[i], B = points[j], C = points[k];
                pair<int, int> U = make_pair(B.first - A.first, B.second - A.second), V = make_pair(C.first - A.first, C.second - A.second);
                int D = 2 * (U.first * V.second - U.second * V.first);
                if (D == 0)
                    continue;
                double centerX = (double) (V.second * (pow(U.first, 2) + pow(U.second, 2)) - U.second * (pow(V.first, 2) + pow(V.second, 2))) / (double) D;
                double centerY = (double) (U.first * (pow(V.first, 2) + pow(V.second, 2)) - V.first * (pow(U.first, 2) + pow(U.second, 2))) / (double) D;
                double radius = sqrt(pow(centerX, 2) + pow(centerY, 2));
                bool allWithin = true;
                for (int p = 0; p < N; p++)
                    if (dist((double) points[p].first, (double) points[p].second, centerX, centerY) > radius)
                        allWithin = false;
                if (allWithin)
                    smallestThree = max(smallestThree, radius * 2);
            }
        }
    }
    
    cout << fixed << setprecision(2) << min((smallestTwo == 0 ? smallestThree : smallestTwo), (smallestThree == 0 ? smallestTwo : smallestThree)) << endl;
    
    return 0;
}
