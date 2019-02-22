#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, r;
    cin >> c >> r;
    
    int x = 0, y = 0, dx, dy;
    cin >> dx >> dy;
    while (dx != 0 || dy != 0) {
        x += dx;
        y += dy;
        
        x = max(min(x, c), 0);
        y = max(min(y, r), 0);
        
        cout << x << " " << y << endl;
        
        cin >> dx >> dy;
    }
    
    return 0;
}
