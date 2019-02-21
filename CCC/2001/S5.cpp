#include <bits/stdc++.h>

using namespace std;

int m, n;

bool solve(vector<string> A, vector<string> B, string a, string b, vector<int> &sequence) {
    if (sequence.size() == m)
        return false;
    if (a != "" && a == b)
        return true;
    for (int i = 0; i < n; i++) {
        vector<int> tempSequence = sequence;
        tempSequence.push_back(i);
        if (solve(A, B, a + A[i], b + B[i], tempSequence)) {
            sequence = tempSequence;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> m >> n;
    
    vector<string> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    
    vector<int> sequence;
    bool possible = solve(A, B, "", "", sequence);
    if (possible) {
        cout << sequence.size() << "\n";
        for (int i = 0; i < sequence.size(); i++)
            cout << (sequence[i] + 1) << "\n";
    } else {
        cout << "No solution.\n";
    }
    
    return 0;
}
