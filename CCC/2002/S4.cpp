#include <bits/stdc++.h>

using namespace std;

int main() {
    int maxPerGroup, numInQueue;
    cin >> maxPerGroup >> numInQueue;
    
    vector<string> names(numInQueue);
    vector<int> times(numInQueue);
    for (int i = 0; i < numInQueue; i++)
        cin >> names[i] >> times[i];
    
    vector<int> fastest(numInQueue + 1, numeric_limits<int>::max()), groupSizes(numInQueue + 1);
    fastest[0] = 0;
    for (int i = 0; i <= numInQueue; i++) {
        int slowestTimeInGroup = 0;
        for (int groupSize = 1; groupSize <= maxPerGroup && i + groupSize <= numInQueue; groupSize++) {
            slowestTimeInGroup = max(slowestTimeInGroup, times[i + groupSize - 1]);
            if (fastest[i] + slowestTimeInGroup < fastest[i + groupSize]) {
                fastest[i + groupSize] = fastest[i] + slowestTimeInGroup;
                groupSizes[i + groupSize] = groupSize;
            }
        }
    }
    
    cout << "Total Time: " << fastest[numInQueue] << "\n";
    
    stack<string> output;
    for (int i = numInQueue - 1; i >= 0; ) {
        int groupSize = groupSizes[i + 1];
        string nextLine = "";
        for (int j = 0; j < groupSize; j++, i--) {
            if (j > 0)
                nextLine = " " + nextLine;
            nextLine = names[i] + nextLine;
        }
        nextLine += "\n";
        output.push(nextLine);
    }
    while (!output.empty()) {
        cout << output.top();
        output.pop();
    }
    
    return 0;
}
