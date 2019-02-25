#include <bits/stdc++.h>

using namespace std;

int main() {
    string op;
    cin >> op;
    
    int adjacency[50][50];
    memset(adjacency, 0, sizeof(adjacency));
    
	adjacency[1][6] = 1;
	adjacency[6][1] = 1;
	adjacency[2][6] = 1;
	adjacency[6][2] = 1;
	adjacency[3][6] = 1;
	adjacency[6][3] = 1;
	adjacency[4][6] = 1;
	adjacency[6][4] = 1;
	adjacency[5][6] = 1;
	adjacency[6][5] = 1;
	adjacency[7][6] = 1;
	adjacency[6][7] = 1;
	adjacency[3][4] = 1;
	adjacency[4][3] = 1;
	adjacency[4][5] = 1;
	adjacency[5][4] = 1;
	adjacency[3][5] = 1;
	adjacency[5][3] = 1;
	adjacency[3][15] = 1;
	adjacency[15][3] = 1;
	adjacency[13][15] = 1;
	adjacency[15][13] = 1;
	adjacency[14][13] = 1;
	adjacency[13][14] = 1;
	adjacency[12][13] = 1;
	adjacency[13][12] = 1;
	adjacency[7][8] = 1;
	adjacency[8][7] = 1;
	adjacency[8][9] = 1;
	adjacency[9][8] = 1;
	adjacency[9][10] = 1;
	adjacency[10][9] = 1;
	adjacency[9][12] = 1;
	adjacency[12][9] = 1;
	adjacency[10][11] = 1;
	adjacency[11][10] = 1;
	adjacency[11][12] = 1;
	adjacency[12][11] = 1;
	adjacency[16][17] = 1;
	adjacency[17][16] = 1;
	adjacency[16][18] = 1;
	adjacency[18][16] = 1;
	adjacency[18][17] = 1;
	adjacency[17][18] = 1;
    
    while (op != "q") {
        if (op == "i") {
            int x, y;
            cin >> x >> y;
            adjacency[x][y] = 1;
            adjacency[y][x] = 1;
        }
        if (op == "d") {
            int x, y;
            cin >> x >> y;
            adjacency[x][y] = 0;
            adjacency[y][x] = 0;
        }
        if (op == "n") {
            int x;
            cin >> x;
            int n = 0;
            for (int y = 1; y < 50; y++)
                n += adjacency[x][y];
            cout << n << endl;
        }
        if (op == "f") {
            int x;
            cin >> x;
            queue< pair<int, int> > bfs;
            bfs.push(make_pair(x, 0));
            int visited[50] = { false };
            int f = 0;
            while (!bfs.empty()) {
                pair<int, int> next = bfs.front();
                bfs.pop();
                
                if (visited[next.first])
                    continue;
                visited[next.first] = true;
                
                if (next.second == 2) {
                    f++;
                    continue;
                }
                
                for (int i = 1; i < 50; i++)
                    if (adjacency[next.first][i])
                        bfs.push(make_pair(i, next.second + 1));
            }
            cout << f << endl;
        }
        if (op == "s") {
            int x, y;
            cin >> x >> y;
            queue< pair<int, int> > bfs;
            bfs.push(make_pair(x, 0));
            int visited[50] = { false };
            int s = -1;
            while (!bfs.empty()) {
                pair<int, int> next = bfs.front();
                bfs.pop();
                
                if (visited[next.first])
                    continue;
                visited[next.first] = true;
                
                if (next.first == y) {
                    s = next.second;
                    break;
                }
                
                for (int i = 1; i < 50; i++)
                    if (adjacency[next.first][i])
                        bfs.push(make_pair(i, next.second + 1));
            }
            if (s == -1)
                cout << "Not connected" << endl;
            else
                cout << s << endl;
        }
        
        cin >> op;
    }
    
    return 0;
}
