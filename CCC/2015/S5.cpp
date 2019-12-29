#include <bits/stdc++.h>

using namespace std;

#define MAXN 3001
#define MAXM 100

int N, M, A[MAXN], B[MAXM], dp[MAXN][2][MAXM][MAXM];

int solve(int pos, int take, int l, int r) {
    if (dp[pos][take][l][r] != -1)
        return dp[pos][take][l][r];
    if (pos == N) {
        if (l <= r) {
            if (take)
                return dp[pos][take][l][r] = B[r] + solve(pos, 0, l, r - 1);
            return dp[pos][take][l][r] = solve(pos, 1, l + 1, r);
        }
        return dp[pos][take][l][r] = 0;
    }
    if (take) {
        dp[pos][take][l][r] = max(solve(pos, 0, l, r), A[pos] + solve(pos + 1, 0, l, r));
        if (l <= r)
            dp[pos][take][l][r] = max(dp[pos][take][l][r], B[r] + solve(pos, 0, l, r - 1));
    } else {
        dp[pos][take][l][r] = solve(pos + 1, 1, l, r);
        if (l <= r)
            dp[pos][take][l][r] = max(dp[pos][take][l][r], solve(pos, 1, l + 1, r));
    }
    return dp[pos][take][l][r];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> B[i];
    sort(B, B + M);

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1, 0, M - 1) << endl;

    return 0;
}
