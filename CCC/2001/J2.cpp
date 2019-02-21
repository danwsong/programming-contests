#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, m, n;
    cin >> x >> m;
    
    bool flag = false;
    for (n = 1; n < m; n++)
        if ((x * n) % m == 1) {
            flag = true;
            break;
        }
    if (flag)
        cout << n << endl;
    else
        cout << "No such integer exists." << endl;
    
    return 0;
}
