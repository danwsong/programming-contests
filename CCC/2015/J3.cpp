#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    string r = "";
    for (int i = 0; i < s.size(); i++) {
        r += s[i];
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
            vector<pair<int, char>> dist(5);
            dist[0] = make_pair(abs((int) s[i] - (int) 'a'), 'a');
            dist[1] = make_pair(abs((int) s[i] - (int) 'e'), 'e');
            dist[2] = make_pair(abs((int) s[i] - (int) 'i'), 'i');
            dist[3] = make_pair(abs((int) s[i] - (int) 'o'), 'o');
            dist[4] = make_pair(abs((int) s[i] - (int) 'u'), 'u');
            sort(dist.begin(), dist.end(), [](pair<int, char> a, pair<int, char> b) {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            });
            r += dist[0].second;
            if (s[i] == 'z')
                r += s[i];
            else if (s[i] + 1 == 'a' || s[i] + 1 == 'e' || s[i] + 1 == 'i' || s[i] + 1 == 'o' || s[i] + 1 == 'u')
                r += (s[i] + 2);
            else
                r += (s[i] + 1);
        }
    }
    cout << r << endl;
    
    return 0;
}
