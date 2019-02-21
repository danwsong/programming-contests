#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> worstRank(n, 1);
    vector<int> cumulative(n);
    vector< pair<int, int> > current(n);
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int score;
            cin >> score;
            cumulative[j] += score;
        }
        for (int j = 0; j < n; j++) {
            current[j] = make_pair(cumulative[j], j);
        }
        sort(current.begin(), current.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });
        int cur = -1, curRank = 0, num = 1;
        for (int j = 0; j < n; j++) {
            if (current[j].first != cur) {
                cur = current[j].first;
                curRank += num;
                num = 1;
            } else {
                num++;
            }
            worstRank[current[j].second] = max(worstRank[current[j].second], curRank);
        }
    }

    int topYodellers = 1, maxScore = current[0].first;
    for (int i = 1; i < n; i++)
        if (current[i].first == maxScore)
            topYodellers++;
    
    for (int i = 0; i < topYodellers; i++)
        cout << "Yodeller " << (current[i].second + 1) << " is the TopYodeller: score " << current[i].first << ", worst rank " << worstRank[current[i].second] << "\n";
    
    return 0;
}
