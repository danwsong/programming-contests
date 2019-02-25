#include <bits/stdc++.h>

using namespace std;

int solve(int fav, int rem, vector< vector<int> > records) {
    if (rem == 0) {
        int sum = 0;
        for (int i = 1; i <= 4; i++)
            sum += records[fav][i];
        for (int i = 1; i <= 4; i++) {
            if (i == fav)
                continue;
            int sum2 = 0;
            for (int j = 1; j <= 4; j++)
                sum2 += records[i][j];
            if (sum2 >= sum)
                return false;
        }
        return 1;
    } else {
        int sum = 0;
        for (int i = 1; i <= 4; i++) {
            for (int j = i + 1; j <= 4; j++) {
                if (records[i][j] == -1) {
                    records[i][j] = 0;
                    records[j][i] = 3;
                    sum += solve(fav, rem - 1, records);
                    records[i][j] = 1;
                    records[j][i] = 1;
                    sum += solve(fav, rem - 1, records);
                    records[i][j] = 3;
                    records[j][i] = 0;
                    sum += solve(fav, rem - 1, records);
                }
            }
        }
        return sum;
    }
}

int main() {
    int T, G;
    cin >> T >> G;
    
    vector< vector<int> > records(5, vector<int>(5, -1));
    
    for (int i = 0; i < G; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (x < y) {
            records[a][b] = 0;
            records[b][a] = 3;
        } else if (x == y) {
            records[a][b] = 1;
            records[b][a] = 1;
        } else {
            records[a][b] = 3;
            records[b][a] = 0;
        }
    }
    
    cout << solve(T, 6 - G, records) << endl;
    
    return 0;
}
