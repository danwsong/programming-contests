#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    n = min(n, 9);
    m = min(m, 9);
    
    int ways = 0;
    for (; n >= 10 - m; n--, ways++);
    
    if (ways == 1) {
        cout << "There is 1 way to get the sum 10.\n";
    } else {
        cout << "There are " << ways << " ways to get the sum 10.\n";
    }
    
    return 0;
}
