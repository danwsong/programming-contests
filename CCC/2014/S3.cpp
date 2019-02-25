#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        
        stack<int> mountain;
        for (int i = 0; i < N; i++) {
            int train;
            cin >> train;
            mountain.push(train);
        }
        stack<int> branch;
        
        int train = 1;
        while (train <= N) {
            if (!mountain.empty() && mountain.top() == train) {
                mountain.pop();
                train++;
            } else if (!branch.empty() && branch.top() == train) {
                branch.pop();
                train++;
            } else if (!mountain.empty() && (branch.empty() || mountain.top() < branch.top())) {
                branch.push(mountain.top());
                mountain.pop();
            } else {
                break;
            }
        }
        if (train == N + 1)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    
    return 0;
}
