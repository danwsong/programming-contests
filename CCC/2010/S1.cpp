#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<string, int>> list;
    for (int i = 0; i < N; i++) {
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        list.push_back(make_pair(s, 2 * a + 3 * b + c));
    }
    
    sort(list.begin(), list.end(), [](pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });
    
    if (N == 0) {
        
    } else if (N == 1) {
        cout << list[0].first << endl;
    } else {
        cout << list[0].first << endl;
        cout << list[1].first << endl;
    }
    
    return 0;
}
