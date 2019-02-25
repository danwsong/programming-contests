#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> bowls(3);
    for (int i = 0; i < 3; i++) {
        cin >> bowls[i];
    }
    
    sort(bowls.begin(), bowls.end());
    
    cout << bowls[1] << endl;
    
    return 0;
}
