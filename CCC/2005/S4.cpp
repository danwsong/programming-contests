#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        vector<string> names(N);
        for (int i = 0; i < N; i++)
            cin >> names[i];
        
        int maxDepth = 1;
        vector<string> tree;
        tree.push_back(names[N - 1]);
        for (int i = 0; i < N; i++) {
            if (tree.size() > 1 && names[i] == tree[tree.size() - 2]) {
                tree.pop_back();
            } else {
                tree.push_back(names[i]);
            }
            maxDepth = max(maxDepth, (int) tree.size());
        }
        
        cout << ((N - (maxDepth - 1) * 2) * 10) << endl;
    }
    
    return 0;
}
