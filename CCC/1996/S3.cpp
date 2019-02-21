#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, string s) {
    if (n == 0 && k == 0)
        cout << s << "\n";
    if (n) {
        if (k) {
            solve(n - 1, k - 1, s + "1");
        }
        solve(n - 1, k, s + "0");
    }
}

int main() {
    int t;
    cin >> t;
    while (t) {
        cout << "The bit patterns are\n";
        int n, k;
        cin >> n >> k;
        
        solve(n, k, "");
        
        t--;
        cout << "\n";
    }
    
    return 0;
}
