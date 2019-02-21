#include <bits/stdc++.h>

using namespace std;

int graph[100][100], money[100][100];

int main() {
    int r, c;
    cin >> r >> c;
    
    while (r || c) {
        for (int i = 0; i < r; i++) {
            string line;
            cin >> line;
            
            for (int j = 0; j < c; j++) {
                if (line[j] == '.')
                    graph[i][j] = 0;
                else if (line[j] == '*')
                    graph[i][j] = -1;
                else
                    graph[i][j] = line[j] - '0';
                money[i][j] = -1;
            }
        }
        
        // starting square
        money[r - 1][0] = graph[r - 1][0];
        
        // up the first column
        for (int i = r - 2; i >= 0 && graph[i][0] >= 0; i--)
            money[i][0] = money[i + 1][0] + graph[i][0];
        
        // loop through all columns
        for (int j = 1; j < c; j++) {
            // down the column
            for (int k = 0; k < r; k++) {
                if (money[k][j - 1] < 0)
                    continue;
                int sum = money[k][j - 1];
                for (int i = k; i < r && graph[i][j] >= 0; i++) {
                    sum += graph[i][j];
                    money[i][j] = max(money[i][j], sum);
                }
            }
            
            // up the column
            for (int k = r - 1; k >= 0; k--) {
                if (money[k][j - 1] < 0)
                    continue;
                int sum = money[k][j - 1];
                for (int i = k; i >= 0 && graph[i][j] >= 0; i--) {
                    sum += graph[i][j];
                    money[i][j] = max(money[i][j], sum);
                }
            }
        }
        
        cout << money[r - 1][c - 1] << endl;
        
        cin >> r >> c;
    }
    
    return 0;
}
