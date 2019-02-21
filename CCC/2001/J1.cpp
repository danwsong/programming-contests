#include <bits/stdc++.h>

using namespace std;

int main() {
    int H;
    cin >> H;
    
    for (int r = -(H / 2); r <= (H / 2); r++) {
        for (int c = 1; c <= H; c++) {
            if (abs(2 * r) + c <= H) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        for (int c = H; c >= 1; c--) {
            if (abs(2 * r) + c <= H) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
