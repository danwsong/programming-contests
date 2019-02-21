#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> start(n), end(m);
    for (int i = 0; i < n; i++)
        cin >> start[i];
    for (int i = 0; i < m; i++)
        cin >> end[i];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << start[i] << " as " << end[j] << "\n";
    
    return 0;
}
