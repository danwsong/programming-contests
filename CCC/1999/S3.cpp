#include <bits/stdc++.h>

using namespace std;

bool isFilled(int x, int y) {
    while (x > 0 || y > 0) {
        if (x % 3 == 1 && y % 3 == 1)
            return false;
        x /= 3;
        y /= 3;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T) {
        int n, b, t, l, r;
        cin >> n >> b >> t >> l >> r;
        b = pow(3, n) - b;
        t = pow(3, n) - t;
        l--;
        r--;
        for (int y = t; y <= b; y++) {
            for (int x = l; x <= r; x++) {
                if (isFilled(x, y))
                    cout << "*";
                else
                    cout << " ";
                if (x < r)
                    cout << " ";
            }
            cout << "\n";
        }
        
        T--;
        cout << "\n";
    }
    
    return 0;
}
