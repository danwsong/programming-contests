#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    
    int seqLen = 2;
    while (a >= b) {
        c = a - b;
        a = b;
        b = c;
        seqLen++;
    }
    cout << seqLen << endl;
    
    return 0;
}
