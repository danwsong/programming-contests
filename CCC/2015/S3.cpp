#include <bits/stdc++.h>

using namespace std;

int main() {
    int gates, planes, docked;
    cin >> gates >> planes;
    vector<int> airport(gates + 1, 0);
    for (docked = 0; docked < planes; docked++) {
        int next;
        cin >> next;
        while (next > 0 && airport[next] > 0)
            next -= airport[next]++;
        if (next <= 0)
            break;
        else
            airport[next]++;
    }
    cout << docked << endl;
    
    return 0;
}
