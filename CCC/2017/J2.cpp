#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int r;
    cin >> r;
    
    int sum = N;
    for (int i = 0; i < r; i++) {
        sum *= 10;
        sum += N;
    }
    cout << sum << endl;
    
    return 0;
}