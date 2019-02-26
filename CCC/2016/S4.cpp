#include <bits/stdc++.h>

using namespace std;

vector<int> riceballs;
vector< vector<int> > dp;

int canCombine(int start, int end) {
    if (dp[start][end] != -1)
        return dp[start][end];
    if (start >= end) {
        dp[start][end] = 1;
        return 1;
    }
    int left = riceballs[start], right = riceballs[end];
    dp[start][end] = 0;
    for (int a = start, b = end; a <= b; ) {
        if (left == right) {
            dp[start][end] = max(dp[start][end], canCombine(start, a) * canCombine(a + 1, b - 1) * canCombine(b, end));
            a++;
            left += riceballs[a];
        }
        if (left < right) {
            a++;
            if (a > end)
                break;
            left += riceballs[a];
        }
        if (right < left) {
            b--;
            if (b < start)
                break;
            right += riceballs[b];
        }
    }
    return dp[start][end];
}

int main() {
    int N;
    cin >> N;
    
    riceballs = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> riceballs[i];
    }
    
    dp = vector< vector<int> >(N, vector<int>(N, -1));

    int maxSize = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += riceballs[k];
            sum *= canCombine(i, j);
            maxSize = max(maxSize, sum);
        }
    }
    cout << maxSize << endl;
    
    return 0;
}
