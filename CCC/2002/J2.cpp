#include <bits/stdc++.h>

using namespace std;

bool consonant(char c) {
    if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y') return true;
    return false;
}

int main() {
    string a;
    cin >> a;
    while (a != "quit!") {
        if (a.size() > 4 && consonant(a[a.size() - 3]) && a[a.size() - 2] == 'o' && a[a.size() - 1] == 'r') {
            a[a.size() - 1] = 'u';
            a += "r";
        }
        cout << a << "\n";
        cin >> a;
    }
    return 0;
}
