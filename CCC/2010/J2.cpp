#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, s;
    cin >> a >> b >> c >> d >> s;
    
    int nikky = 0, byron = 0;
    for (int i = 0; i < s; i++) {
        nikky += (i % (a + b) < a) ? 1 : -1;
        byron += (i % (c + d) < c) ? 1 : -1;
    }
    
    cout << (nikky == byron ? "Tied" : (nikky > byron ? "Nikky" : "Byron")) << endl;
    
    return 0;
}
