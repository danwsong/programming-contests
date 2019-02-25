#include <bits/stdc++.h>

using namespace std;

int main() {
    string a = "IOSHXZN";
    string b;
    cin >> b;
    bool flag2 = false;
    for (int i = 0; i < b.size(); i++) {
        bool flag1 = false;
        for (int j = 0; j < a.size(); j++) {
            if (b[i] == a[j]) {
                flag1 = true;
                break;
            }
        }
        if (!flag1) {
            flag2 = true;
            break;
        }
    }
    
    cout << (flag2 ? "NO" : "YES") << endl;
    
    return 0;
}
