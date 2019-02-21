#include <bits/stdc++.h>

using namespace std;

int main() {
    int start, N;
    cin >> start >> N;
    string days[7] = { "Sun", "Mon", "Tue", "Wed", "Thr", "Fri", "Sat" };
    for (int i = 0; i < 7; i++)
        cout << days[i] << (i == 6 ? "\n" : " ");
    for (int i = 1; i - start + 1 <= N; i++) {
        if (i >= start) {
            if (i - start + 1 < 10) {
                cout << "  " << (i - start + 1);
            } else {
                cout << " " << (i - start + 1);
            }
        } else {
            cout << "   ";
        }
        if ((i - 1) % 7 == 6 || i - start + 1 == N) {
            cout << "\n";
        } else {
            cout << " ";
        }
    }
    
    return 0;
}
