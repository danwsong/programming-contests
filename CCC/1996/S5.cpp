#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T) {
        int N;
        cin >> N;
        
        vector<int> x(N), y(N);
        for (int i = 0; i < N; i++)
            cin >> x[i];
        for (int i = 0; i < N; i++)
            cin >> y[i];
        
        int i = 0, j = 0, maxDist = 0;
        while (i < N && j < N) {
            if (y[j] >= x[i]) {
                maxDist = max(maxDist, j - i);
                j++;
            } else {
                i++;
            }
        }
        cout << "The maximum distance is " << maxDist << "\n";
        
        T--;
    }
    
    return 0;
}
