#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > points;

struct line {
    int a, b, dist;
    
    line(int a, int b) {
        this->a = a;
        this->b = b;
        this->dist = (points[a].first - points[b].first) * (points[a].first - points[b].first) + (points[a].second - points[b].second) * (points[a].second - points[b].second);
    }
};

int main() {
    int N;
    cin >> N;
    
    points = vector< pair<int, int> >(N + 1);
    points[0] = make_pair(0, 0);
    for (int i = 1; i <= N; i++)
        cin >> points[i].first >> points[i].second;
    
    vector<line> lines;
    for (int a = 0; a <= N; a++)
        for (int b = a + 1; b <= N; b++)
            lines.push_back(line(a, b));
    sort(lines.begin(), lines.end(), [](line a, line b) {
        return a.dist < b.dist;
    });
    
    vector<int> best(N + 1), pbest(N + 1), pdist(N + 1);
    for (line l : lines) {
        int a = l.a, b = l.b, dist = l.dist;
        
        if (dist > pdist[a]) {
            pdist[a] = dist;
            pbest[a] = best[a];
        }
        if (dist > pdist[b]) {
            pdist[b] = dist;
            pbest[b] = best[b];
        }
        
        if (a == 0) {
            best[a] = max(best[a], pbest[b]);
        } else {
            best[a] = max(best[a], pbest[b] + 1);
            best[b] = max(best[b], pbest[a] + 1);
        }
    }
    cout << (best[0] + 1) << endl;
    
    return 0;
}
