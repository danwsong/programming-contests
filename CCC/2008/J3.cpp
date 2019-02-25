#include <bits/stdc++.h>

using namespace std;

int conv(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    if (c == ' ')
        return 26;
    if (c == '-')
        return 27;
    if (c == '.')
        return 28;
    return -1;
}

int main() {
    string s;
    getline(cin, s);
    
    int x = conv(s[0]) % 6, y = conv(s[0]) / 6, dist = x + y;
    for (int i = 1; i < s.size(); i++) {
        dist += abs(x - conv(s[i]) % 6) + abs(y - conv(s[i]) / 6);
        x = conv(s[i]) % 6;
        y = conv(s[i]) / 6;
    }
    dist += abs(x - 5) + abs(y - 4);
    
    cout << dist << endl;
    
    return 0;
}
