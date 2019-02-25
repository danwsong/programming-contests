#include <bits/stdc++.h>

using namespace std;

int main() {
    int maxWeight, N;
    cin >> maxWeight >> N;
    vector<int> trains(N);
    for (int i = 0; i < N; i++)
        cin >> trains[i];
    
    int i, sum, overload = false;
    for (i = 0; i < N; i++) {
        sum = 0;
        for (int j = max(i, 4); j < i + 4; j++)
            sum += trains[j - 4];
        if (sum > maxWeight) {
            overload = true;
            break;
        }
    }
    cout << (overload ? i - 1 : i) << endl;
    
    return 0;
}
