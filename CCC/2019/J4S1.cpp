#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    int hFlips = 0, vFlips = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'H')
            hFlips++;
        if (s[i] == 'V')
            vFlips++;
    }
    
    hFlips %= 2;
    vFlips %= 2;
    
    vector< vector<int> > grid = { { 1, 2 }, { 3, 4 } };
    if (hFlips) {
        vector< vector<int> > temp = grid;
        temp[0][0] = grid[1][0];
        temp[0][1] = grid[1][1];
        temp[1][0] = grid[0][0];
        temp[1][1] = grid[0][1];
        grid = temp;
    }
    if (vFlips) {
        vector< vector<int> > temp = grid;
        temp[0][0] = grid[0][1];
        temp[0][1] = grid[0][0];
        temp[1][0] = grid[1][1];
        temp[1][1] = grid[1][0];
        grid = temp;
    }
    
    cout << grid[0][0] << " " << grid[0][1] << endl;
    cout << grid[1][0] << " " << grid[1][1] << endl;
    
    return 0;
}
