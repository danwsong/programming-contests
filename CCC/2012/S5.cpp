#include <bits/stdc++.h>

using namespace std;

int dp[25][25];

int solve(int x, int y) {
    if (x < 0 || y < 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    return dp[x][y] = solve(x - 1, y) + solve(x, y - 1);
}

int main() {
    int x, y;
    cin >> x >> y;
    
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            dp[i][j] = -1;
    
    dp[0][0] = 1;
    
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int cx, cy;
        cin >> cx >> cy;
        cx--;
        cy--;
        
        dp[cx][cy] = 0;
    }
    
    cout << solve(x - 1, y - 1) << endl;
    
    return 0;
}
