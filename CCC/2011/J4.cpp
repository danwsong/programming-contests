#include <bits/stdc++.h>

using namespace std;

int main() {
    int drillPlan[8][14] = {
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    int map[201][401];
    for (int i = 0; i <= 200; i++)
        for (int j = 0; j <= 400; j++)
            map[i][j] = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 14; j++)
            map[i + 1][j + 197] = drillPlan[i][j];
    
    int x = -1, y = -5;
    
    string op;
    int dist;
    cin >> op >> dist;
    while (op != "q") {
        int dx = 0, dy = 0;
        if (op == "d")
            dy = -1;
        if (op == "u")
            dy = 1;
        if (op == "l")
            dx = -1;
        if (op == "r")
            dx = 1;
        
        bool intersected = false;
        for (int i = 0; i < dist; i++) {
            x += dx;
            y += dy;
            if (map[-y][x + 200])
                intersected = true;
            map[-y][x + 200] = 1;
        }
        
        cout << x << " " << y << " " << (intersected ? "DANGER" : "safe") << endl;
        if (intersected)
            break;
        
        cin >> op >> dist;
    }
    
    return 0;
}
