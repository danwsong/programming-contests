#include <bits/stdc++.h>

using namespace std;

int main() {
    int K;
	string s;
    cin >> K >> s;
    
    for (int i = 0; i < s.size(); i++) {
        s[i] = (s[i] - 'A' + 26 - (3 * (i + 1) + K) % 26) % 26 + 'A';
    }
    
    cout << s << endl;
    
    return 0;
}
