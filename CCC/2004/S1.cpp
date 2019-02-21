#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T) {
        vector<string> words(3);
        for (int i = 0; i < 3; i++)
            cin >> words[i];
            
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.size() < b.size();
        });
        
        bool prefixFree = true;
        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                if (mismatch(words[i].begin(), words[i].end(), words[j].begin()).first == words[i].end())
                    prefixFree = false;
        
        bool suffixFree = true;
        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                if (mismatch(words[i].rbegin(), words[i].rend(), words[j].rbegin()).first == words[i].rend())
                    suffixFree = false;
        
        bool fixFree = prefixFree && suffixFree;
        
        cout << (fixFree ? "Yes" : "No") << "\n";
        
        T--;
    }
    
    return 0;
}
