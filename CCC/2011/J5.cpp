#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue< vector<bool> > createCombos;
    createCombos.push(vector<bool>());
    while (createCombos.size() < pow(2, N - 1)) {
        vector<bool> cur = createCombos.front();
        createCombos.pop();
        
        vector<bool> next1 = cur, next2 = cur;
        next1.push_back(true);
        createCombos.push(next1);
        next2.push_back(false);
        createCombos.push(next2);
    }

    vector< vector<bool> > combinations;
    while (!createCombos.empty()) {
        combinations.push_back(createCombos.front());
        createCombos.pop();
    }
    
    vector< vector<int> > invite(N, vector<int>());
    
    for (int i = 0; i < N - 1; i++) {
        int j;
        cin >> j;
        j--;
        invite[j].push_back(i);
    }
    
    int solution = combinations.size();
    for (int k = 0; k < combinations.size(); k++) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (i != j && combinations[k][i] && !combinations[k][j]) {
                    bool isChild = false;
                    stack<int> dfs;
                    dfs.push(i);
                    while (!dfs.empty()) {
                        int u = dfs.top();
                        dfs.pop();
                        
                        if (u == j) {
                            isChild = true;
                            break;
                        }
                        
                        for (int v = 0; v < invite[u].size(); v++) {
                            dfs.push(invite[u][v]);
                        }
                    }
                    if (isChild) {
                        solution--;
                        goto invalid;
                    }
                }
            }
        }
    invalid:
        continue;
    }
    cout << solution << endl;
    
    return 0;
}
