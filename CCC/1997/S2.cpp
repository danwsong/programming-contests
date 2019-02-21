#include <bits/stdc++.h>

using namespace std;

int isNasty(int N) {
    vector<int> factors;
    int isFactor[32001];
    memset(isFactor, 0, sizeof(isFactor));
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            factors.push_back(i);
            isFactor[i] = 1;
            if (i * i != N) {
                factors.push_back(N / i);
                isFactor[N / i] = 1;
            }
        }
    }
    for (int i = 0; i < factors.size(); i++) {
        for (int j = 0; j < factors.size(); j++) {
            for (int k = 0; k < factors.size(); k++) {
                if (i != j && j != k && i != k) {
                    if (factors[i] * factors[j] == N && factors[i] - factors[j] - factors[k] > 0 && isFactor[factors[i] - factors[j] - factors[k]] && factors[i] * factors[j] == factors[k] * (factors[i] - factors[j] - factors[k])) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T) {
        int N;
        cin >> N;
        cout << N << " is " << (isNasty(N) ? "" : "not ") << "nasty\n";
        
        T--;
    }
    
    return 0;
}
