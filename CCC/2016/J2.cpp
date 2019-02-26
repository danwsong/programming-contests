#include <bits/stdc++.h>

using namespace std;

int main() {
    int magic[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> magic[i][j];
        }
    }
    
    vector<int> sums;
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += magic[i][j];
        }
        sums.push_back(sum);
    }
    for (int j = 0; j < 4; j++) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += magic[i][j];
        }
        sums.push_back(sum);
    }
    
    bool flag = false;
    for (int i = 1; i < sums.size(); i++)l
        if (sums[0] != sums[i])
            flag = true;
            
    cout << (flag ? "not magic" : "magic") << endl;
    
    return 0;
}
