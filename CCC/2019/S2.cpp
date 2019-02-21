#include <bits/stdc++.h>

using namespace std;

bool isPrime(int N) {
    for (int i = 2; i * i <= N; i++)
        if (N % i == 0)
            return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        int i;
        for (i = N; i >= 0; i--) {
            if (isPrime(i) && isPrime(2 * N - i)) {
                break;
            }
        }
        cout << i << " " << 2 * N - i << endl;
    }
    
    return 0;
}
