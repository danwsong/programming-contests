#include <bits/stdc++.h>

using namespace std;

int main() {
    double tx, ty, tz, sx, sy, sz;
    cin >> tx >> ty >> tz >> sx >> sy >> sz;
    
    double x = sx - tx, y = sy - ty, z = sz - tz;
    
    double closest = x * x + y * y + z * z;
    
    double d;
    string turn;
    cin >> d >> turn;
    while (turn != "E") {
        x -= d;
        if (x * x + x * d < 0)
            closest = min(closest, y * y + z * z);
        closest = min(closest, x * x + y * y + z * z);
            
        double temp = x;
        if (turn == "L") {
            x = y;
            y = -temp;
        }
        if (turn == "R") {
            x = -y;
            y = temp;
        }
        if (turn == "U") {
            x = z;
            z = -temp;
        }
        if (turn == "D") {
            x = -z;
            z = temp;
        }
        
        cin >> d >> turn;
    }
    x -= d;
    if (x * x + x * d < 0)
        closest = min(closest, y * y + z * z);
    closest = min(closest, x * x + y * y + z * z);
    
    cout << fixed << setprecision(2) << sqrt(closest) << endl;
    
    return 0;
}
