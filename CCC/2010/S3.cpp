#include <bits/stdc++.h>

using namespace std;

int solve(int hoseLength, vector<int> houses) {
    int minHydrants = houses.size(), range = hoseLength * 2;
    for (int i = 0; i < houses.size() && houses[i] <= houses[0] + range; i++) {
        int hydrants = 1, lastAddress = houses[i];
        for (int j = i + 1; j < houses.size() && houses[j] + range < houses[i] + 1000000; j++) {
            if (houses[j] > lastAddress) {
                hydrants++;
                lastAddress = houses[j] + range;
            }
        }
        minHydrants = min(minHydrants, hydrants);
    }
    return minHydrants;
}

int main() {
    int numHouses, numHydrants;
    cin >> numHouses;
    vector<int> houses(numHouses);
    for (int i = 0; i < numHouses; i++)
        cin >> houses[i];
    sort(houses.begin(), houses.end());
    cin >> numHydrants;
    
    int lo = -1, hi = 1000000;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid, houses) > numHydrants)
            lo = mid;
        else
            hi = mid;
    }
    cout << hi << endl;
    
    return 0;
}
