#include <bits/stdc++.h>

using namespace std;

int main() {
    int grid[3][3], xCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string num;
            cin >> num;
            
            if (num == "X") {
                grid[i][j] = numeric_limits<int>::max();
                xCount++;
            }
            else
                grid[i][j] = stoi(num);
        }
    }
    
    if (xCount == 9) {
        xCount = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = 0;
            }
        }
    }
    while (xCount > 0) {
        bool oneUnknown = false, filled = false;
        for (int i = 0; i < 3; i++) {
            int cur[3], unknown = 0;
            for (int j = 0; j < 3; j++) {
                cur[j] = grid[i][j];
                if (cur[j] == numeric_limits<int>::max())
                    unknown++;
            }
            
            if (unknown == 1) {
                if (cur[0] == numeric_limits<int>::max()) {
                    grid[i][0] = grid[i][1] * 2 - grid[i][2];
                } else if (cur[1] == numeric_limits<int>::max()) {
                    grid[i][1] = (grid[i][0] + grid[i][2]) / 2;
                } else if (cur[2] == numeric_limits<int>::max()) {
                    grid[i][2] = grid[i][1] * 2 - grid[i][0];
                }
                oneUnknown = true;
                xCount--;
            }
        }
        for (int j = 0; j < 3; j++) {
            int cur[3], unknown = 0;
            for (int i = 0; i < 3; i++) {
                cur[i] = grid[i][j];
                if (cur[i] == numeric_limits<int>::max())
                    unknown++;
            }
            
            if (unknown == 1) {
                if (cur[0] == numeric_limits<int>::max()) {
                    grid[0][j] = grid[1][j] * 2 - grid[2][j];
                } else if (cur[1] == numeric_limits<int>::max()) {
                    grid[1][j] = (grid[0][j] + grid[2][j]) / 2;
                } else if (cur[2] == numeric_limits<int>::max()) {
                    grid[2][j] = grid[1][j] * 2 - grid[0][j];
                }
                oneUnknown = true;
                xCount--;
            }
        }
        if (!oneUnknown) {
            for (int i = 0; i < 3; i++) {
                int cur[3], unknown = 0;
                for (int j = 0; j < 3; j++) {
                    cur[j] = grid[i][j];
                    if (cur[j] == numeric_limits<int>::max())
                        unknown++;
                }
                
                if (!filled && unknown == 2) {
                    if (cur[0] != numeric_limits<int>::max()) {
                        if ((i == 0 && ((grid[2][1] != numeric_limits<int>::max() && abs(grid[2][1] - grid[i][0]) % 2 == 1) || (grid[2][2] != numeric_limits<int>::max() && abs(grid[2][2] - grid[i][0]) % 2 == 1))) || (i == 2 && ((grid[0][1] != numeric_limits<int>::max() && abs(grid[0][1] - grid[i][0]) % 2 == 1) || (grid[0][2] != numeric_limits<int>::max() && abs(grid[0][2] - grid[i][0]) % 2 == 1)))) {
                            grid[i][1] = grid[i][0] + 1;
                            grid[i][2] = grid[i][0] + 2;
                        } else {
                            grid[i][1] = grid[i][0];
                            grid[i][2] = grid[i][0];
                        }
                    } else if (cur[1] != numeric_limits<int>::max()) {
                        if ((i == 0 && ((grid[2][0] != numeric_limits<int>::max() && abs(grid[2][0] - grid[i][1]) % 2 == 1) || (grid[2][2] != numeric_limits<int>::max() && abs(grid[2][2] - grid[i][1]) % 2 == 1))) || (i == 2 && ((grid[0][0] != numeric_limits<int>::max() && abs(grid[0][0] - grid[i][1]) % 2 == 1) || (grid[0][2] != numeric_limits<int>::max() && abs(grid[0][2] - grid[i][1]) % 2 == 1)))) {
                            grid[i][0] = grid[i][1] - 1;
                            grid[i][2] = grid[i][1] + 1;
                        } else {
                            grid[i][0] = grid[i][1];
                            grid[i][2] = grid[i][1];
                        }
                    } else if (cur[2] != numeric_limits<int>::max()) {
                        if ((i == 0 && ((grid[2][1] != numeric_limits<int>::max() && abs(grid[2][1] - grid[i][2]) % 2 == 1) || (grid[2][0] != numeric_limits<int>::max() && abs(grid[2][0] - grid[i][2]) % 2 == 1))) || (i == 2 && ((grid[0][1] != numeric_limits<int>::max() && abs(grid[0][1] - grid[i][2]) % 2 == 1) || (grid[0][0] != numeric_limits<int>::max() && abs(grid[0][0] - grid[i][2]) % 2 == 1)))) {
                            grid[i][1] = grid[i][2] - 1;
                            grid[i][0] = grid[i][2] - 2;
                        } else {
                            grid[i][1] = grid[i][2];
                            grid[i][0] = grid[i][2];
                        }
                    }
                    filled = true;
                    xCount -= 2;
                }
            }
            for (int j = 0; j < 3; j++) {
                int cur[3], unknown = 0;
                for (int i = 0; i < 3; i++) {
                    cur[i] = grid[i][j];
                    if (cur[i] == numeric_limits<int>::max())
                        unknown++;
                }
                
                if (!filled && unknown == 2) {
                    if (cur[0] != numeric_limits<int>::max()) {
                        if ((j == 0 && ((grid[1][2] != numeric_limits<int>::max() && abs(grid[1][2] - grid[0][j]) % 2 == 1) || (grid[2][2] != numeric_limits<int>::max() && abs(grid[2][2] - grid[0][j]) % 2 == 1))) || (j == 2 && ((grid[1][0] != numeric_limits<int>::max() && abs(grid[1][0] - grid[0][j]) % 2 == 1) || (grid[2][0] != numeric_limits<int>::max() && abs(grid[2][0] - grid[0][j]) % 2 == 1)))) {
                            grid[1][j] = grid[0][j] + 1;
                            grid[2][j] = grid[0][j] + 2;
                        } else {
                            grid[1][j] = grid[0][j];
                            grid[2][j] = grid[0][j];
                        }
                    } else if (cur[1] != numeric_limits<int>::max()) {
                        if ((j == 0 && ((grid[0][2] != numeric_limits<int>::max() && abs(grid[0][2] - grid[1][j]) % 2 == 1) || (grid[2][2] != numeric_limits<int>::max() && abs(grid[2][2] - grid[1][j]) % 2 == 1))) || (j == 2 && ((grid[0][0] != numeric_limits<int>::max() && abs(grid[0][0] - grid[1][j]) % 2 == 1) || (grid[2][0] != numeric_limits<int>::max() && abs(grid[2][0] - grid[1][j]) % 2 == 1)))) {
                            grid[0][j] = grid[1][j] - 1;
                            grid[2][j] = grid[1][j] + 1;
                        } else {
                            grid[0][j] = grid[1][j];
                            grid[2][j] = grid[1][j];
                        }
                    } else if (cur[2] != numeric_limits<int>::max()) {
                        if ((j == 0 && ((grid[1][2] != numeric_limits<int>::max() && abs(grid[1][2] - grid[2][j]) % 2 == 1) || (grid[0][2] != numeric_limits<int>::max() && abs(grid[0][2] - grid[2][j]) % 2 == 1))) || (j == 2 && ((grid[1][0] != numeric_limits<int>::max() && abs(grid[1][0] - grid[2][j]) % 2 == 1) || (grid[0][0] != numeric_limits<int>::max() && abs(grid[0][0] - grid[2][j]) % 2 == 1)))) {
                            grid[1][j] = grid[2][j] - 1;
                            grid[0][j] = grid[2][j] - 2;
                        } else {
                            grid[1][j] = grid[2][j];
                            grid[0][j] = grid[2][j];
                        }
                    }
                    filled = true;
                    xCount -= 2;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j];
            if (j + 1 < 3)
                cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
