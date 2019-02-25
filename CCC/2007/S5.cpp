#include <bits/stdc++.h>

using namespace std;

int dp[501][30000];
int pins[30000];
int sums[30000];
int N, width;

int main() {
    int T;
    scanf("%d", &T);
    while (T) {
        int K;
        scanf("%d %d %d", &N, &K, &width);
        for (int i = 0; i < N; i++)
                dp[0][i] = 0;
        for (int i = 0; i < N; i++)
            scanf("%d", &pins[i]);
        sums[0] = 0;
        for (int i = 0; i < width; i++) {
            sums[0] += pins[i];
        }
        for (int i = 1; i <= N - width; i++) {
            sums[i] = sums[i - 1] - pins[i - 1] + pins[i + width - 1];
        }
        for (int i = N - width + 1; i < N; i++) {
            sums[i] = sums[i - 1] - pins[i - 1];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = N - 1; j >= 0; j--) {
                dp[i][j] = 0;
                if (j + 1 < N)
                    dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                int sum = sums[j];
                if (j + width < N)
                    sum += dp[i - 1][j + width];
                dp[i][j] = max(dp[i][j], sum);
            }
        }
        int solution = 0;
        for (int i = 0; i < N; i++) {
            solution = max(solution, dp[K][i]);
        }
        printf("%d\n", solution);
        T--;
    }
    
    return 0;
}
