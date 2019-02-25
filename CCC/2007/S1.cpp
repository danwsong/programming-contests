#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int y, m, d;
        cin >> y >> m >> d;
        if (y < 1989) {
            cout << "Yes" << endl;
        } else if (y == 1989 && m < 2) {
            cout << "Yes" << endl;
        } else if (y == 1989 && m == 2 && d <= 27) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
