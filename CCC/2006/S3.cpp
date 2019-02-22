#include <bits/stdc++.h>

using namespace std;

struct vec {
    double x, y;
    
    vec() {
        this->x = 0;
        this->y = 0;
    }
    
    vec(double x, double y) {
        this->x = x;
        this->y = y;
    }
    
    vec add(vec a) {
        return vec(x + a.x, y + a.y);
    }
    
    vec sub(vec a) {
        return vec(x - a.x, y - a.y);
    }
    
    vec mul(double a) {
        return vec(x * a, y * a);
    }

    double mag() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    double dot(vec a) {
        return x * a.x + y * a.y;
    }

    vec proj(vec a) {
        return a.mul(dot(a) / pow(a.mag(), 2));
    }
};

int main() {
    vec r, j;
    cin >> r.x >> r.y >> j.x >> j.y;

    int N;
    cin >> N;

    int blocking = 0;
    while (N--) {
        bool outside = true, collision = false;

        int V;
        cin >> V;

        vec prevLineToV;
        for (int i = 0; i < V; i++) {
            vec v;
            cin >> v.x >> v.y;

            vec lineToV = v.sub(j).sub(v.sub(j).proj(r.sub(j)));

            if (r.sub(j).dot(v.sub(j)) > 0 && j.sub(r).dot(v.sub(r)) > 0)
                outside = false;
            
            if (lineToV.mag() < 0.0000000000001 || prevLineToV.dot(lineToV) < 0)
                collision = true;

            prevLineToV = lineToV;
        }

        if (!outside && collision)
            blocking++;
    }
    cout << blocking << endl;
    
    return 0;
}
