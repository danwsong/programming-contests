#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int cost = 0;
    while (N > 1) {
        int factor;
        for (factor = 2; factor * factor <= N && N % factor; factor++);
        
        if (factor < N && N % factor == 0) {
            factor = N / factor;
            N -= factor;
            cost += N / factor;
        } else {
            N--;
            cost += N;
        }
    }
    cout << cost << endl;
    
    return 0;
}
