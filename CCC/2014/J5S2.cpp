#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> a(N), b(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];
        
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) {
            flag = false;
            break;
        }
        int index = find(b.begin(), b.end(), a[i]) - b.begin();
        if (*find(a.begin(), a.end(), a[index]) != b[i]) {
            flag = false;
            break;
        }
    }
    
    if (flag) {
        cout << "good" << endl;
    } else {
        cout << "bad" << endl;
    }
    
    return 0;
}
