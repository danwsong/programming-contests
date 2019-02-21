#include <bits/stdc++.h>

using namespace std;

double dist(pair<double, double> a, pair<double, double> b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main() {
    double w, h, dx, dy;
    cin >> w >> h >> dx >> dy;
    
    double m = dy / (w - dx), startM = m;
    
    double x = dx, y = 0, startX = x, startY = y;
    int hits = -1;
    while (true) {
        if (((x < 5 || x > w - 5) && (y == 0 || y == h)) || ((y < 5 || y > h - 5) && (x == 0 || x == w)) || (startX == x && startY == y && m == startM && hits != -1))
            break;
        vector< pair<double, double> > points;
        double b = y - m * x;
        // left hit
        if (x == 0) {
            // intersection with bottom
            points.push_back(make_pair(-b / m, 0));
            // intersection with right
            points.push_back(make_pair(w, m * w + b));
            // intersection with top
            points.push_back(make_pair((h - b) / m, h));
        }
        // bottom hit
        if (y == 0) {
            // intersection with left
            points.push_back(make_pair(0, b));
            // intersection with right
            points.push_back(make_pair(w, m * w + b));
            // intersection with top
            points.push_back(make_pair((h - b) / m, h));
        }
        // right hit
        if (x == w) {
            // intersection with left
            points.push_back(make_pair(0, b));
            // intersection with bottom
            points.push_back(make_pair(-b / m, 0));
            // intersection with top
            points.push_back(make_pair((h - b) / m, h));
        }
        // top hit
        if (y == h) {
            // intersection with left
            points.push_back(make_pair(0, b));
            // intersection with bottom
            points.push_back(make_pair(-b / m, 0));
            // intersection with right
            points.push_back(make_pair(w, m * w + b));
        }
        sort(points.begin(), points.end(), [x, y, w, h](pair<double, double> a, pair<double, double> b) {
            if (a.first > w || a.first < 0 || a.second > h || a.second < 0)
                return false;
            if (b.first > w || b.first < 0 || b.second > h || b.second < 0)
                return true;
            return dist(a, make_pair(x, y)) < dist(b, make_pair(x, y));
        });
        double factor = pow(10, 10);
        x = round(points[0].first * factor) / factor;
        y = round(points[0].second * factor) / factor;
        m = -m;
        hits++;
    }
    if (startX == x && startY == y && startM == m)
        hits = 0;
    cout << hits << "\n";
    
    return 0;
}
