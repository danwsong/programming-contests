#include <bits/stdc++.h>

using namespace std;

vector< vector< vector<int> > > dp;

int solve(int n, int k, int min) {
    if (dp[n][k][min] != -1)
        return dp[n][k][min];
    if (n == k || k == 1) {
        dp[n][k][min] = 1;
        return 1;
    }
    int ways = 0;
    for (int i = min; i <= n / k; i++) {
        ways += solve(n - i, k - 1, i);
    }
    dp[n][k][min] = ways;
    return ways;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    dp = vector<  vector<vector<int> > >(n + 1, vector< vector<int> >(k + 1, vector<int>(n + 1, -1)));
    
    cout << solve(n, k, 1) << endl;
    
    return 0;
}
