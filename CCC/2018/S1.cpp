#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<double> villages(N);
    for (int i = 0; i < N; i++) {
        cin >> villages[i];
    }
    
    sort(villages.begin(), villages.end());
    
    vector<double> borders(N - 1);
    for (int i = 0; i < borders.size(); i++)
        borders[i] = (villages[i] + villages[i + 1]) / 2;
    
    double minSize = villages[N - 1] - villages[0];
    for (int i = 0; i < borders.size() - 1; i++)
        minSize = min(minSize, borders[i + 1] - borders[i]);
    
    cout << fixed << setprecision(1) << minSize << endl;
    
    return 0;
}