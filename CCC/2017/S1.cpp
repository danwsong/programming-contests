#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> swifts(N), semaphores(N);
    for (int i = 0; i < N; i++)
        cin >> swifts[i];
    for (int i = 0; i < N; i++)
        cin >> semaphores[i];
    
    int swiftSum = 0, semaphoreSum = 0, maxDay = -1;
    for (int i = 0; i < N; i++) {
        swiftSum += swifts[i];
        semaphoreSum += semaphores[i];
        if (swiftSum == semaphoreSum)
            maxDay = i;
    }
    
    cout << maxDay + 1 << endl;
    
    return 0;
}