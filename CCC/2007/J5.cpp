#include <bits/stdc++.h>

using namespace std;

vector<int> motels;
int minTravel, maxTravel;
long long dp[7001];

long long solve(int distanceTravelled) {
    if (dp[distanceTravelled] != -1)
        return dp[distanceTravelled];
    dp[distanceTravelled] = 0;
    for (int i = 0; i < motels.size(); i++)
        if ((motels[i] - distanceTravelled) >= minTravel && (motels[i] - distanceTravelled) <= maxTravel) {
            dp[distanceTravelled] += solve(motels[i]);
        }
    return dp[distanceTravelled];
}

int main() {
    cin >> minTravel >> maxTravel;
    
    int N;
    cin >> N;
    
    motels = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };
    for (int i = 0; i < N; i++) {
        int motel;
        cin >> motel;
        motels.push_back(motel);
    }
    
    for (int i = 0; i < 7000; i++)
        dp[i] = -1;
    dp[7000] = 1;
    
    cout << solve(0) << "\n";
    
    return 0;
}
