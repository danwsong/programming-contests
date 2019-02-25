#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> dp;

int solve(int N) {
    if (dp[N] != -1)
        return dp[N];
    dp[N] = 0;
    for (int i = 0; i < graph[N].size(); i++) {
        dp[N] += solve(graph[N][i]);
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    
    graph = vector<vector<int>>(N, vector<int>());
    dp = vector<int>(N, -1);
    int a, b;
    do {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        a--;
        b--;
        graph[b].push_back(a);
    } while (true);
    
    dp[0] = 1;
    
    cout << solve(N - 1) << endl;
    
    return 0;
}
