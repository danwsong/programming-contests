#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a %= 4;
    b %= 4;
    c %= 4;
    d %= 4;
    
    int e[] = {0, 461, 431, 420}, g[] = {0, 130, 160, 118}, f[] = {0, 100, 57, 70}, h[] = {0, 167, 266, 75};
    
    int calories = e[a] + f[b] + g[c] + h[d];
    
    cout << "Your total Calorie count is " << calories << ".\n";
    
    return 0;
}
