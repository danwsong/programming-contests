#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    long T;
    cin >> N >> T;
    
    vector<long> life(N), newLife(N);
    string line;
    cin >> line;
    for (int i = 0; i < N; i++)
        life[i] = line[i] - '0';
    
    for (long k = 60; k >= 0; k--) {
        if ((T >> k) & 1) {
            long steps = (1L << k) % N, steps2 = (N - steps) % N;
            for (int i = 0; i < N; i++)
                newLife[i] = life[(i + steps) % N] ^ life[(i + steps2) % N];
            for (int i = 0; i < N; i++)
                life[i] = newLife[i];
        }
    }
    
    for (int i = 0; i < N; i++)
        cout << life[i];
    cout << endl;
    
    return 0;
}
