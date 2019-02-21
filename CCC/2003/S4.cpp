#include <bits/stdc++.h>

using namespace std;

int longestCommonPrefix(string a, string b) {
    for (int i = 0; i < (int) min(a.size(), b.size()); i++)
        if (a[i] != b[i])
            return i;
    return (int) min(a.size(), b.size());
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        
        vector<string> suffixes;
        for (int i = 0; i < s.size(); i++)
            suffixes.push_back(s.substr(i));
        sort(suffixes.begin(), suffixes.end());
        
        int count = (int) suffixes[0].size() + 1;
        for (int i = 1; i < s.size(); i++) {
            int lcp = longestCommonPrefix(suffixes[i], suffixes[i - 1]);
            count += (int) suffixes[i].size() - lcp;
        }
        
        cout << count << "\n";
    }
    
    return 0;
}
