#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> frequency(1001, 0);
    for (int i = 0; i < N; i++) {
        int freq;
        cin >> freq;
        frequency[freq]++;
    }
    
    vector<pair<int, int>> indexed;
    for (int i = 1; i <= 1000; i++)
        if (frequency[i] != 0)
            indexed.push_back(make_pair(i, frequency[i]));
    
    sort(indexed.begin(), indexed.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    
    int solution = abs(indexed[0].first - indexed[1].first);
    for (int i = 2; i < indexed.size() && indexed[1].second == indexed[i].second; i++)
        solution = max(solution, abs(indexed[0].first - indexed[i].first));
    cout << solution << endl;
    
    return 0;
}
