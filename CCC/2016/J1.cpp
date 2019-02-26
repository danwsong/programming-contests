#include <bits/stdc++.h>

using namespace std;

int main() {
    int wins = 0;
    for (int i = 0; i < 6; i++) {
        string next;
        cin >> next;
        if (next == "W")
            wins++;
    }
    
    if (wins > 4)
		cout << 1 << endl;
    else if (wins > 2)
		cout << 2 << endl;
    else if (wins > 0)
		cout << 3 << endl;
    else
		cout << -1 << endl;
    
    return 0;
}
