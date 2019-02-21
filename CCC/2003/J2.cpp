#include <bits/stdc++.h>

using namespace std;

int main() {
    int C;
    
    for (cin >> C; C != 0; cin >> C) {
        int factor = (int) round(sqrt(C));
        while (C % factor != 0) factor--;
        cout << "Minimum perimeter is " << (2 * (factor + C / factor)) << " with dimensions " << factor << " x " << (C / factor) << endl;
    }
    
    return 0;
}
