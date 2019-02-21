#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
    
    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int level, width, x;
    cin >> level >> width >> x;
    
    vector<point> fractal, nextFractal;
    
    fractal.push_back(point(0, 1));
    fractal.push_back(point(width, 1));
    for (int l = 1; l <= level; l++) {
        nextFractal = vector<point>();
        for (int i = 0; i < fractal.size() - 1; i++) {
            nextFractal.push_back(fractal[i]);
            if (fractal[i].y == fractal[i + 1].y) {
                int w = (fractal[i + 1].x - fractal[i].x) / 3;
                nextFractal.push_back(point(fractal[i].x + w, fractal[i].y));
                nextFractal.push_back(point(fractal[i].x + w, fractal[i].y + w));
                nextFractal.push_back(point(fractal[i].x + 2 * w, fractal[i].y + w));
                nextFractal.push_back(point(fractal[i].x + 2 * w, fractal[i].y));
            }
            if (fractal[i].x == fractal[i + 1].x) {
                int w = (fractal[i + 1].y - fractal[i].y) / 3;
                nextFractal.push_back(point(fractal[i].x, fractal[i].y + w));
                nextFractal.push_back(point(fractal[i].x - w, fractal[i].y + w));
                nextFractal.push_back(point(fractal[i].x - w, fractal[i].y + 2 * w));
                nextFractal.push_back(point(fractal[i].x, fractal[i].y + 2 * w));
            }
        }
        nextFractal.push_back(fractal[fractal.size() - 1]);
        
        fractal = nextFractal;
    }
    
    for (int y = 0; y <= width / 2 + 1; y++) {
        bool found = false;
        for (int i = 0; i < fractal.size() && !found; i++) {
            if (fractal[i].x == fractal[i + 1].x && fractal[i].y < fractal[i + 1].y && x == fractal[i].x && y >= fractal[i].y && y <= fractal[i + 1].y) {
                cout << y << " ";
                found = true;
            }
            if (fractal[i].x == fractal[i + 1].x && fractal[i].y > fractal[i + 1].y && x == fractal[i].x && y <= fractal[i].y && y >= fractal[i + 1].y) {
                cout << y << " ";
                found = true;
            }
            if (fractal[i].x < fractal[i + 1].x && fractal[i].y == fractal[i + 1].y && x >= fractal[i].x && x <= fractal[i + 1].x && y == fractal[i].y) {
                cout << y << " ";
                found = true;
            }
            if (fractal[i].x > fractal[i + 1].x && fractal[i].y == fractal[i + 1].y && x <= fractal[i].x && x >= fractal[i + 1].x && y == fractal[i].y) {
                cout << y << " ";
                found = true;
            }
        }
    }
    
    return 0;
}
