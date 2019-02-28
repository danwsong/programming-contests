#include <bits/stdc++.h>

using namespace std;

int N;
vector<long> dp1, dp2;

long solve(int n) {
    long answer = 0;
    for (int j = 1; j <= sqrt(n); j++) {
        answer += (n / j - n / (j + 1)) * dp1[j];
    }
    for (int j = 2; n / j > sqrt(n); j++) {
        if (n / j >= sqrt(N)) {
            answer += dp2[N / (n / j)];
        } else {
            answer += dp1[n / j];
        }
    }
    return answer;
}

int main() {
    cin >> N;
    
    dp1 = vector<long>(sqrt(N) + 1);
    dp2 = vector<long>(sqrt(N) + 1);
    
    dp1[1] = 1;
    for (int j = 1; j <= sqrt(N); j++) {
        dp1[j] = solve(j);
    }
    for (int j = sqrt(N); j >= 1; j--) {
        dp2[j] = solve(N / j);
    }
    cout << dp2[1] << endl;
    
    return 0;
}