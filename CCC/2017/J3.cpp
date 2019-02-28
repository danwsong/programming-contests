#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, t;
    cin >> a >> b >> c >> d >> t;
    
    int distance = t - abs(a - c) - abs(b - d);
    cout << ((distance >= 0 && distance % 2 == 0) ? "Y" : "N") << endl;
    
    return 0;
}