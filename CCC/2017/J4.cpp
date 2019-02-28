#include <bits/stdc++.h>

using namespace std;

int main() {
    int D;
    cin >> D;
    
    int days = D / (60 * 12), remainder = D % (60 * 12);
    int d = 0, r = 0;
    for (int m = 0; m < 60 * 12; m++) {
        int hour = (m / 60 + 11) % 12 + 1, minute = m % 60;
        int d1 = hour / 10, d2 = hour % 10, d3 = minute / 10, d4 = minute % 10;
        if (d4 - d3 == d3 - d2 && d3 - d2 == d2 - d1 || d1 == 0 && d4 - d3 == d3 - d2) {
            d++;
            if (m <= remainder)
                r++;
        }
    }
    d *= days;
    cout << d + r << endl;
    
    return 0;
}