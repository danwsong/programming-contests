#include <bits/stdc++.h>

using namespace std;

int presses(char c) {
    if (c >= 'a' && c <= 'c')
        return c - 'a' + 1;
    if (c >= 'd' && c <= 'f')
        return c - 'd' + 1;
    if (c >= 'g' && c <= 'i')
        return c - 'g' + 1;
    if (c >= 'j' && c <= 'l')
        return c - 'j' + 1;
    if (c >= 'm' && c <= 'o')
        return c - 'm' + 1;
    if (c >= 'p' && c <= 's')
        return c - 'p' + 1;
    if (c >= 't' && c <= 'v')
        return c - 't' + 1;
    if (c >= 'w' && c <= 'z')
        return c - 'w' + 1;
    return -1;
}

int key(char c) {
    if (c >= 'a' && c <= 'c')
        return 2;
    if (c >= 'd' && c <= 'f')
        return 3;
    if (c >= 'g' && c <= 'i')
        return 4;
    if (c >= 'j' && c <= 'l')
        return 5;
    if (c >= 'm' && c <= 'o')
        return 6;
    if (c >= 'p' && c <= 's')
        return 7;
    if (c >= 't' && c <= 'v')
        return 8;
    if (c >= 'w' && c <= 'z')
        return 9;
    return -1;
}

int main() {
    string s;
    cin >> s;
    while (s != "halt") {
        int t = 0, currNum = -1;
        for (int i = 0; i < s.size(); i++) {
            t += presses(s[i]);
            if (key(s[i]) == currNum)
                t += 2;
            currNum = key(s[i]);
        }
        cout << t << endl;
        cin >> s;
    }
    
    return 0;
}
