#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T) {
        vector<int> nums(T);
        for (int i = 0; i < T; i++)
            cin >> nums[i];

        vector<int> differences(T - 1);
        for (int i = 0; i < T - 1; i++) {
            differences[i] = nums[i + 1] - nums[i];
        }
        
        int minCycleLength = T - 1;
        for (int cycleLength = 1; cycleLength < T - 1; cycleLength++) {
            bool isCycle = true;
            for (int i = 0, j = i + cycleLength; j < T - 1; i++, j++)
                if (differences[i] != differences[j])
                    isCycle = false;
            if (isCycle) {
                minCycleLength = cycleLength;
                break;
            }
        }
        cout << minCycleLength << endl;
        
        cin >> T;
    }
    
    return 0;
}
