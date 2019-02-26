#include <bits/stdc++.h>

using namespace std;

int main() {
    int J, A;
    cin >> J >> A;
    
    vector<string> jerseys(J);
    for (int i = 0; i < J; i++)
        cin >> jerseys[i];
        
    int ans = 0;
    for (int i = 0; i < A; i++) {
        string j;
        int n;
        cin >> j >> n;
        n--;
        if (jerseys[n] != "T") {
            if (j == "S" || j == jerseys[n] || (j == "M" && jerseys[n] == "L")) {
                ans++;
                jerseys[n] = "T";
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
