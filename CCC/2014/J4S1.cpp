#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, m;
    cin >> N >> m;
    
    vector<int> friends(N);
    for (int i = 0; i < N; i++)
        friends[i] = i + 1;
    
    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;
        vector<bool> removeFriend(friends.size());
        for (int j = d - 1; j < friends.size(); j += d) {
            removeFriend[j] = true;
        }
        for (int j = friends.size() - 1; j >= 0; j--) 
            if (removeFriend[j])
                friends.erase(friends.begin() + j);
    }
    
    for (int i = 0; i < friends.size(); i++) {
        cout << friends[i] << endl;
    }
     
    return 0;
}
