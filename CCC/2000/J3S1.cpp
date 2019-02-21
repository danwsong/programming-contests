#include <bits/stdc++.h>

using namespace std;

int main() {
    int q, a, b, c;
    cin >> q >> a >> b >> c;
    
    int plays = 0;
    while (q) {
        q--;
        if (plays % 3 == 0) a++;
        if (a % 35 == 0) q += 30;
        plays++;
        if (!q) break;
        q--;
        if (plays % 3 == 1) b++;
        if (b % 100 == 0) q += 60;
        plays++;
        if (!q) break;
        q--;
        if (plays % 3 == 2) c++;
        if (c % 10 == 0) q += 9;
        plays++;
    }
    cout << "Martha plays " << plays << " times before going broke." << endl;
    
    return 0;
}
